//
// Created by 风格福德宫 on 2022/4/24.
//

#ifndef ZYUC_LAB2GRAMMER_H
#define ZYUC_LAB2GRAMMER_H
#include <string>
#include <vector>
#include <map>
#include "../Lexer/lexer.h"
#include "AST.h"
using namespace std;
class Lab2Grammer {
    AST* root;
    vector<AST* >ast;
    vector<Token*>::iterator begin;
    vector<Token*>::iterator end;
    //运算符优先级
    map<string,int> BinopPD;
    Token* CurToken;
public:
    Lab2Grammer(vector<Token*>&list){
        root= nullptr;
        begin=list.begin();
        end=list.end();
        BinopPD["<"]=10;
        BinopPD[">"]=10;
        BinopPD["+"]=20;
        BinopPD["-"]=20;
        BinopPD["*"]=40;
        BinopPD["/"]=40;
        BinopPD["=="]=10;
    };
    Token* GetNextToken();
    AST* ParsePrimary();
    AST* ParseNumAST();
    AST* Error(string s);
    AST* ParseParentExp();
    AST* ParseIdentifierAST();
    AST* ParseExpression();
    AST* ParseBinOpRHS(int level,AST *LHS);
    AST* ParseWhileAST();
    AST* Parse();
    AST* ParseIFAST();
    AST* ParseAssgin();
    int GetBinopPrecedence();
    void mainloop();
    void printAST();
    vector<AST* >& GetAST(){return ast;}
};


#endif //ZYUC_LAB2GRAMMER_H
