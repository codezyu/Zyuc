#include "lexer.h"
#include <cmath>
using namespace std;
int IsMatch(string word,string pattern){
    return regex_match(word,regex(pattern));
}
void Lexer::scan() {
    while(!input.eof()) {
        while (isspace(input.peek()))
            input.get();
        vector<char> token;
        if (isalpha(input.peek())) {
            do {
                token.emplace_back(input.get());
            } while (isalpha(input.peek()) || isdigit(input.peek()));
            string value(token.begin(), token.end());
            if (IsMatch(value, TYPE)) {
                if(value=="int")
                    tokenList.emplace_back(new Token(INTTYPE,value));
                else if(value=="double")
                    tokenList.emplace_back(new Token(REALTYPE,value));
            } else if (IsMatch(value, KeyWordPattern)) {
                if(value=="while")
                tokenList.emplace_back(new Token(WHILE,value));
                else if(value=="if")
                    tokenList.emplace_back(new Token(IF,value));
                else if(value=="do")
                    tokenList.emplace_back(new Token(DO,value));
                else if(value=="then")
                    tokenList.emplace_back(new Token(THEN,value));
                else if(value=="else")
                    tokenList.emplace_back(new Token(ELSE,value));
            } else if (IsMatch(value, IDENTIFILIER)) {
                tokenList.emplace_back(new Token(IDNETIFIER,value));
            } else {
                errorList.emplace_back(value);
            }
        } else if (isdigit(input.peek())) {
            do {
                token.emplace_back(input.get());
            } while (isalpha(input.peek()) || input.peek() == '.' || isdigit(input.peek()));
            string value(token.begin(), token.end());
            if (IsMatch(value, INTNUMBER)) {
                int n = 10;
                if (value.find('o') != string::npos|| value.find('O') != string::npos) {
                    n = 8;
                    value.erase(std::remove(value.begin(), value.end(), 'o'), value.end());
                    value.erase(std::remove(value.begin(), value.end(), 'O'), value.end());
                }
                if (value.find('x') != string::npos|| value.find('X') != string::npos) {
                    n = 16;
                }
                int *num=new int();
                num[0]=stoi(value,0,n);
                tokenList.emplace_back(new Token(INT,num));
            } else if (IsMatch(value, DOUBLENUM)) {
                stringstream ss;
                double *x=new double();
                if (value.find('o') != string::npos || value.find('O') != string::npos) {
                    value.erase(std::remove(value.begin(), value.end(), 'o'), value.end());
                    value.erase(std::remove(value.begin(), value.end(), 'O'), value.end());
                    string x1, x2;
                    ss << value;
                    getline(ss, x1, '.');
                    getline(ss, x2);
                    x[0]=stoi(x1, 0, 8)+ stoi(x2, 0, 8)*pow(8,-(int)(x2.size()));
                }
                if (value.find('x') != string::npos || value.find('X') != string::npos) {
                    value.erase(std::remove(value.begin(), value.end(), 'x'), value.end());
                    value.erase(std::remove(value.begin(), value.end(), 'X'), value.end());
                    string x1, x2;
                    ss << value;
                    getline(ss, x1, '.');
                    getline(ss, x2);
                    x[0] = stoi(x1, 0, 16) + stoi(x2, 0, 16) * pow(16, -(int)(x2.size()));
                }else{
                    x[0]= stod(value);
                }
                tokenList.emplace_back(new Token(REAL,x));
            } else {
                errorList.emplace_back(value);
            }
        } else {
            do {
                token.emplace_back(input.peek());
                string temp(token.begin(), token.end());
                if(!IsMatch(temp,OperatorPattern)){
                    token.pop_back();
                    break;
                }
                else {
                    input.get();
                }
            } while (!isalpha(input.peek()) && !isdigit(input.peek())&&!isspace(input.peek())&&!input.eof());
            string value(token.begin(), token.end());
            if (IsMatch(value, OperatorPattern)) {
                if(value=="-")
                tokenList.emplace_back(new Token(MINUS,value));
                else if(value=="+")
                    tokenList.emplace_back(new Token(PLUS,value));
                else if(value=="*")
                    tokenList.emplace_back(new Token(MULTIPLY,value));
                else if(value=="/")
                    tokenList.emplace_back(new Token(DIVISION,value));
                else if(value==">")
                    tokenList.emplace_back(new Token(GREATER,value));
                else if(value=="(")
                    tokenList.emplace_back(new Token(LEFTBRACKET,value));
                else if(value==")")
                    tokenList.emplace_back(new Token(RIGHTBRACKET,value));
                else if(value=="==")
                    tokenList.emplace_back(new Token(EQUAL,value));
                else if(value=="=")
                    tokenList.emplace_back(new Token(ASSIGNMENT,value));
                else if(value=="<")
                    tokenList.emplace_back(new Token(LESSER,value));
            } else {
                errorList.emplace_back(value);
            }
        }
    }
}

void Lexer::show() {
    for(int i=0;i<tokenList.size();i++){
        cout<<TokenTypeName[tokenList[i]->type]<<":";
        if(tokenList[i]->type==INT)
            cout<<*(tokenList[i]->value.intval);
        else if(tokenList[i]->type==REAL)
            cout<<*(tokenList[i]->value.doubleval);
        else
            cout<<tokenList[i]->value.stringval;
        cout<<endl;
    }
}