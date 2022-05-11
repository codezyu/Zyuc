#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include "Parser/GrammerReWrite.h"
#include "Lexer/lexer.h"
#include "Parser/Lab2Grammer.h"
#include "Parser/Visitor.h"
using namespace std;
int main() {
    ifstream  afile;
    afile.open("file.txt", ios::in );
    Lexer lexer(afile);
    lexer.scan();
    lexer.show();
    GetGrammerByCsv test("S");
    map<string,vector<string>> mymap=test.ReadGrammer("Parser/production.csv");
//    test.EliminateInDirect();
////    test.clear();
    test.EliminateDirect();
    test.showproduction();
    Lab2Grammer grammer(lexer.tokenList);
    grammer.mainloop();
    IRCodeVisitor* visitor=new IRCodeVisitor();
    vector<AST* >tree=grammer.GetAST();
    for(vector<AST*>::iterator iter=tree.begin();iter!=tree.end();iter++){
        visitor->visit(*iter);
        visitor->PrintIRCode();
        visitor->ConvertIRCodeToLanguage();
    }

}
