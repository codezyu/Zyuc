//
// Created by 风格福德宫 on 2022/5/3.
//

#ifndef ZYUC_VISITOR_H
#define ZYUC_VISITOR_H
#include "BaseVisitor.h"
#include "SymbolTable.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
class VALUE{
public:
    union value{
        int* IntVal;
        double* DoubleVal;
        std::string StringVal;
    public:
        value(){
            new(&StringVal) string ;
        }
        ~value(){
            StringVal.~string();
        }
    }num;
    int type;
    void get(int& result){
        result=*num.IntVal;
    }
    void get(double& result ){
        result= *num.DoubleVal;
    }
    void get(std::string& result ){
        result=num.StringVal;
    }
    string print(){
        if(type==0)
            return to_string(*num.IntVal);
        else if(type==1){
            return to_string(*num.DoubleVal);
        }
        else if(type==2){
            return num.StringVal;
        }
    }
};
class IRCode {
public:
    std::string Op;
    VALUE* arg1;
    VALUE* arg2;
    VALUE* result;
    IRCode(){
        arg1=new VALUE();
        arg2=new VALUE();
        result=new VALUE();
    }
    string print(){
        string s="<"+Op+",";
        if(arg1!= nullptr){
            s+=arg1->print();
        }
        else{
            s+="_";
        }
        s+=",";
        if(arg2!= nullptr){
            s+=arg2->print();
        }
        else{
            s+="_";
        }
        s+=",";
        if(result!= nullptr){
            s+=result->print();
        }
        else{
            s+="_";
        }
        return s+">";
    }
};
struct cmp  //自定义比较规则
{
    bool operator() (const string& str1, const string& str2)
    {
       stringstream ss1(str1);
       char c1;
       int t1,t2;
       ss1>>c1>>t1;
        stringstream ss2(str2);
        ss2>>c1>>t2;
        return t1<t2;
    }
};

class IRCodeVisitor: public Visitor{
public:
    int count;
    int ListCount;
    SymbolTable symbolTable;
    map<string,IRCode*,cmp> IR;
    VALUE* value;
    IRCodeVisitor():count(0),ListCount(1){
    }
    void init(){

    }
    string GetTemp();
    string GetIndex();
    virtual void visit(const VariableAST* ast);
    void visit(const NumAST* ast);
    void visit(const BinOpAST* ast);
    void visit(const AssginAST* ast);
    void visit(const IfAST* ast);
    void visit(const WhileAST* ast);
    void visit(AST *ast){
        ast->accept(this);
    }
    void PrintIRCode();
    int* NewCpoy(int *a);
    double *NewCopy(double *a);
    void AssginValue(VALUE *arg);
    void ConvertIRCodeToLanguage();
};


#endif //ZYUC_VISITOR_H
