//
// Created by 风格福德宫 on 2022/5/3.
//
#include "Visitor.h"

void IRCodeVisitor::visit(const BinOpAST *ast) {
    if(ast== nullptr)
        return;
    IRCode* temp=new IRCode();
    value=new VALUE();
    temp->Op=ast->op;
    value->type=-1;
    ast->left->accept(this);
    AssginValue(temp->arg1);
    value->type=-1;
    ast->right->accept(this);
    AssginValue(temp->arg2);
    if(temp->arg1->type!=2&&temp->arg2->type!=2){
        if(temp->arg1->type==0&&temp->arg2->type==0){
            int a1=*temp->arg1->num.IntVal;
            int a2=*temp->arg2->num.IntVal;
            int* result=new int();
            if(temp->Op=="+")
                *result=a1+a2;
            else if(temp->Op=="-")
                *result=a1-a2;
            else if(temp->Op=="*")
                *result=a1*a2;
            else if(temp->Op=="/")
                *result=a1/a2;
            else if(temp->Op==">")
                *result=a1>a2;
            else if(temp->Op=="<")
                *result=a1<a2;
            else if(temp->Op=="==")
                *result=a1==a2;
            temp->result->type=0;
            temp->result->num.IntVal=result;
            string index="L"+ to_string(ListCount);
            IR[index]=temp;
            value->type=0;
            int* v=new int();
            *v=*result;
            value->num.IntVal=v;
        }
        else{
            double a1;
            if(temp->arg1->type=0)
                a1=(double )*temp->arg1->num.IntVal;
            else
                a1=*temp->arg1->num.DoubleVal;
            double a2;
            if(temp->arg2->type=0)
                a2=(double )*temp->arg2->num.IntVal;
            else
                a2=*temp->arg2->num.DoubleVal;
            double* result=new double ();
            if(temp->Op=="+")
                *result=a1+a2;
            else if(temp->Op=="-")
                *result=a1-a2;
            else if(temp->Op=="*")
                *result=a1*a2;
            else if(temp->Op=="/")
                *result=a1/a2;
            else if(temp->Op==">")
                *result=a1>a2;
            else if(temp->Op=="<")
                *result=a1<a2;
            else if(temp->Op=="==")
                *result=a1==a2;
            temp->result->type=1;
            temp->result->num.DoubleVal=result;
            value->type=1;
            double * v=new double();
            *v=*result;
            value->num.DoubleVal=v;
        }
    }
    else{
        temp->result->type=2;
        temp->result->num.StringVal=GetTemp();
        value->type=2;
        value->num.StringVal=temp->result->num.StringVal;
    }
    string index=GetIndex();
    IR[index]=temp;
}

void IRCodeVisitor::visit(const AssginAST *ast) {
    if(ast== nullptr)
        return;
    IRCode* temp=new IRCode();
    temp->Op="=";
    value->type=-1;
    ast->target->accept(this);
    AssginValue(temp->result);
    value->type=-1;
    ast->value->accept(this);
    AssginValue(temp->arg1);
    temp->arg2= nullptr;
    string index=GetIndex();
    IR[index]=temp;
}

void IRCodeVisitor::visit(const NumAST *ast) {
    if(ast== nullptr)
        return;
    if(ast->type=="int")
    {
        value->num.IntVal= NewCpoy(ast->number.Inum);
        value->type=0;
    }
    else if(ast->type=="double")
    {
        value->num.DoubleVal= NewCopy(ast->number.Dnum);
        value->type=1;
    }
}

void IRCodeVisitor::visit(const VariableAST *ast) {
    value->num.StringVal=ast->id;
    value->type=2;
}

string IRCodeVisitor::GetIndex() {
    string index="L"+ to_string(ListCount);
    ListCount++;
    return index;
}

string IRCodeVisitor::GetTemp() {
    string t="T"+ to_string(count);
    while(symbolTable.label.count(t)){
        count++;
        t="T"+ to_string(count);
    }
    symbolTable.label[t]=1;
    return t;
}

void IRCodeVisitor::visit(const IfAST *ast) {
    if(ast== nullptr)
        return;
    IRCode* temp=new IRCode();
    ast->comparator->accept(this);
    string index=GetIndex();
    temp->Op="if";
    AssginValue(temp->arg1);
    value->type=2;
    value->num.StringVal=GetIndex();
    ListCount--;
    AssginValue(temp->arg2);
    if(ast->body== nullptr){
        AssginValue(temp->result);
    }
    else{
        ast->body->accept(this);
        value->type=2;
        value->num.StringVal=GetIndex();
        AssginValue(temp->result);
        if(ast->then!= nullptr)
            ast->then->accept(this);
    }
    IR[index]=temp;
}

void IRCodeVisitor::visit(const WhileAST *ast) {
    if(ast== nullptr)
        return;
    IRCode* temp=new IRCode();
    ast->comparator->accept(this);
    string index=GetIndex();
    temp->Op="if";
    AssginValue(temp->arg1);
    if(ast->body!= nullptr)
    {
        value->type=2;
        value->num.StringVal=GetIndex();
        AssginValue(temp->arg2);
        ListCount--;
        ast->body->accept(this);
    }
    //无条件跳转
    IRCode* temp1=new IRCode();
    temp1->Op="if";
    temp1->arg1= nullptr;
    value->type=2;
    value->num.StringVal=index;
    AssginValue(temp1->arg2);
    temp1->result= nullptr;
    string end=GetIndex();
    IR[end]=temp1;
    if(ast->body== nullptr)
    {
        value->type=2;
        value->num.StringVal=end;
        AssginValue(temp->arg2);
    }
    value->type=2;
    value->num.StringVal=GetIndex();
    ListCount--;
    AssginValue(temp->result);
    IR[index]=temp;
}

void IRCodeVisitor::PrintIRCode() {
    for(map<string,IRCode*,cmp>::iterator iter=IR.begin();iter!=IR.end();iter++){
        cout<<iter->first<<":";
        cout<<iter->second->print()<<endl;
    }
}

int *IRCodeVisitor::NewCpoy(int *a) {
    int *b=new int();
    *b=*a;
    return b;
}

double *IRCodeVisitor::NewCopy(double* a) {
    double *b=new double();
    *b=*a;
    return b;
}

void IRCodeVisitor::AssginValue(VALUE *arg) {
    if(value->type==0)
    {
        arg->num.IntVal= NewCpoy(value->num.IntVal);
        arg->type=0;
    }
    else if(value->type==1)
    {
        arg->num.DoubleVal= NewCopy(value->num.DoubleVal);
        arg->type=1;
    }
    else if(value->type==2){
        arg->num.StringVal=value->num.StringVal;
        arg->type=2;
    }
}

void IRCodeVisitor::ConvertIRCodeToLanguage() {
    for(map<string,IRCode*,cmp>::iterator iter=IR.begin();iter!=IR.end();iter++){
        cout<<iter->first<<":";
        if(iter->second->Op=="if"){
           if(iter->second->arg1!= nullptr){
               cout<<"if "+iter->second->arg1->print()+"!=0 "+"goto "+iter->second->arg2->print()\
               +"\n goto "+iter->second->result->print()+"\n";
           }
           else{
               cout<<"goto "+iter->second->arg2->print()+"\n";
           }
        }
        else if(iter->second->Op=="="){
            cout<<iter->second->result->print()+":="+iter->second->arg1->print()+"\n";

        }
        else {
            cout<<iter->second->result->print()+":="+iter->second->arg1->print()+iter->second->Op+iter->second->arg2->print()+"\n";
        }
    }
    cout<<GetIndex()+": end"<<endl;
}
