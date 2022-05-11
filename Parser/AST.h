//
// Created by 风格福德宫 on 2022/4/27.
//
#pragma once
#ifndef ZYUC_AST_H
#define ZYUC_AST_H
#include <string>
#include "BaseAST.h"
using namespace std;
class VariableAST:public AST{
public:
    string id;
    VariableAST(string _id):id(_id){}
    string print(){
        return "Name("+id+")";
    }
    virtual void accept(Visitor *visitor);
};
class NumAST :public AST{
public:
    union num{
        double* Dnum;
        int* Inum;
    }number;
    string type;
    NumAST(double* _num){
        number.Dnum=_num;
        type="double";
    }
    NumAST(int* _num){
        number.Inum=_num;
        type="int";
    }
    string print(){
        if(type=="int")
            return "Value("+to_string(*number.Inum)+")";
        if(type=="double")
            return "Value("+to_string(*number.Dnum)+")";
    }
    void accept(Visitor* visitor);
};
class BinOpAST:public AST{
public:
    string op;
    AST* left,*right;
    BinOpAST(AST *_left,string _op,AST *_right): left(_left),op(_op),right(_right){}
    string print(){
        return "BinOp(left="+left->print()+",op= "+op+",right="+right->print()+")";
    }
    void accept(Visitor* visitor);
};
class AssginAST:public AST{
public:
    AST* target;
    AST* value;
    AssginAST(AST* _target,AST* _value):target(_target),value(_value){};
    string print(){
        return "Assgin(target="+target->print()+",value="+value->print()+")";
    }
    void accept(Visitor* visitor);
};
class IfAST:public AST{
public:
    AST *comparator,*body,*then;
    IfAST(AST* _comparator,AST* _body,AST* _then):comparator(_comparator),body(_body),then(_then){}
    string print(){
        string s="IF(comparator="+comparator->print()+",body=";
        if(body== nullptr)
            s+="null";
        else
            s+=body->print();
        s+=",then=";
        if(then== nullptr)
            s+="null)";
        else
            s+=then->print()+")";
        return s;
    }
    void accept(Visitor* visitor);
};
class WhileAST:public AST{
public:
    AST *comparator,*body;
    WhileAST(AST* _comparator,AST* _body):comparator(_comparator),body(_body){}
    string print(){
        string s="WHILE(comparator="+comparator->print()+",body=";
        if(body== nullptr)
            s+="null)";
        else
            s+=body->print()+")";
        return s;
    }
    void accept(Visitor* visitor);
};
#endif //ZYUC_AST_H
