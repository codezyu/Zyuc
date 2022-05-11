//
// Created by 风格福德宫 on 2022/4/24.
//

#include "Lab2Grammer.h"

Token *Lab2Grammer::GetNextToken() {
    if(begin!=end)
    {
        Token* temp= *begin;
        CurToken=temp;
        begin++;
        return temp;
    }
    else {
        CurToken= nullptr;
        return nullptr;
    }
}
AST *Lab2Grammer::ParseNumAST() {
    AST* r;
    if(CurToken== nullptr)
        return nullptr;
    if(CurToken->type==INT)
        r=new NumAST((*CurToken).value.intval);
    else{
        r=new NumAST((*CurToken).value.doubleval);
    }
    GetNextToken();
    return r;
}
AST *Lab2Grammer::ParseParentExp() {
    GetNextToken();
   AST * b= ParseExpression();
   if(!b)
       return nullptr;
   if(CurToken->value.stringval!=")")
       return Error("expected ')'");
   GetNextToken();
    return b;
}
AST *Lab2Grammer::ParseIdentifierAST() {
    if(CurToken== nullptr)
        return nullptr;
    AST* ast=new VariableAST(CurToken->value.stringval);
    GetNextToken();
    return ast;
}

AST *Lab2Grammer::ParseExpression() {
    AST *LHS=ParsePrimary();
    if(!LHS)
        return nullptr;
    return ParseBinOpRHS(0,LHS);
}

AST *Lab2Grammer::ParsePrimary() {
    if(CurToken== nullptr)
        return nullptr;
    if(CurToken->type==IDNETIFIER){
        return ParseIdentifierAST();
    }
    else if(CurToken->type==LEFTBRACKET)
        return ParseParentExp();
    else
        return ParseNumAST();
}

AST *Lab2Grammer::Error(string s) {
    cout<< s;
    return nullptr;
}

AST *Lab2Grammer::ParseBinOpRHS(int ExpPd, AST* LHS) {
    while(1){
        int level= GetBinopPrecedence();
        if(level<ExpPd)
            return LHS;
        string BinOp=CurToken->value.stringval;
        GetNextToken();
        AST* RHS=ParsePrimary();
        if(!RHS)
            return nullptr;
        int Next=GetBinopPrecedence();
        if(level<Next)
            RHS= ParseBinOpRHS(level+1,RHS);
        if(RHS== nullptr)
            return nullptr;
        LHS=new BinOpAST(LHS,BinOp,RHS);
    }
}
int Lab2Grammer::GetBinopPrecedence() {
    if(CurToken==nullptr)
        return -1;
    string BinOp=CurToken->value.stringval;
    if(BinopPD.count(BinOp)>0)
        return BinopPD[BinOp];
    else
        return -1;
}

void Lab2Grammer::mainloop() {
    //启动
    GetNextToken();
    while(1) {
        root=Parse();
        printAST();
        ast.emplace_back(root);
        if(CurToken== nullptr)
            break;
    }
}

void Lab2Grammer::printAST() {
    if(root== nullptr)
        return;
    cout<<root->print()<<endl;
}


AST *Lab2Grammer::ParseAssgin() {
    if(CurToken== nullptr)
        return nullptr;
    else
    {
        AST* target=new VariableAST(CurToken->value.stringval);
        GetNextToken();
        if(CurToken->type==ASSIGNMENT){
            GetNextToken();
            AST* value=ParseExpression();
            if(value!= nullptr)
            {
                return new AssginAST(target,value);
            }
            else{
                return Error("expected value on the '=' right");
            }
        }
        else
            return target;
    }
}
AST *Lab2Grammer::ParseWhileAST() {
    if(CurToken== nullptr)
        return nullptr;
    GetNextToken();
    AST* comp=ParseExpression();
    if(CurToken!= nullptr&&CurToken->type==DO){
        GetNextToken();
        AST* then=Parse();
        return new WhileAST(comp,then);
    }
    else{
        return new WhileAST(comp, nullptr);
    }
}
AST *Lab2Grammer::Parse() {
    if(CurToken== nullptr)
        return nullptr;
    else if(CurToken->type==IDNETIFIER){
        root=ParseAssgin();
    }
    else if(CurToken->type==WHILE){
        root=ParseWhileAST();
    }
    else if(CurToken->type==IF){
        root=ParseIFAST();
    }
    else{
        root= nullptr;
    }
    return root;
}

AST *Lab2Grammer::ParseIFAST() {
    GetNextToken();
    AST* cmp=ParseExpression();
    if(CurToken!= nullptr&&CurToken->type==THEN){
        GetNextToken();
        AST* body=Parse();
        if(CurToken!= nullptr&&CurToken->type==ELSE)
        {
            GetNextToken();
            AST* then=Parse();
            return new IfAST(cmp,body,then);
        }
        else{
            return new IfAST(cmp,body, nullptr);
        }
    }
    else{
        return new IfAST(cmp, nullptr, nullptr);
    }
}


