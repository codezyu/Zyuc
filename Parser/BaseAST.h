//
// Created by 风格福德宫 on 2022/5/3.
//

#ifndef ZYUC_BASEAST_H
#define ZYUC_BASEAST_H
#include <string>
class Visitor;
using namespace std;
class AST {
public:
    virtual string print() = 0;
    virtual void accept(Visitor* visitor)=0;
};

#endif //ZYUC_BASEAST_H
