//
// Created by 风格福德宫 on 2022/4/26.
//

#ifndef ZYUC_SYMBOLTABLE_H
#define ZYUC_SYMBOLTABLE_H
#include <string>
#include <map>
using namespace std;
enum SymbolType{
    VAR,
    LABEL,
};
class SymbolTable {
public:
    map<string,int>label;
};


#endif //ZYUC_SYMBOLTABLE_H
