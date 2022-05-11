//
// Created by 风格福德宫 on 2022/5/3.
//
#pragma once
#ifndef ZYUC_BASEVISITOR_H
#define ZYUC_BASEVISITOR_H
#include "AST.h"
using namespace std;
class VariableAST;
class NumAST;
class BinOpAST;
class AssginAST;
class IfAST;
class WhileAST;
class Visitor {
public:
    virtual void visit(const VariableAST* ast)=0;
    virtual void visit(const NumAST* ast)=0;
    virtual void visit(const BinOpAST* ast)=0;
    virtual void visit(const AssginAST* ast)=0;
    virtual void visit(const IfAST* ast)=0;
    virtual void visit(const WhileAST* ast)=0;
};


#endif //ZYUC_BASEVISITOR_H
