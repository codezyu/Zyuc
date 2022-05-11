//
// Created by 风格福德宫 on 2022/4/21.
//

#ifndef ZYUC_GRAMMERREWRITE_H
#define ZYUC_GRAMMERREWRITE_H

#endif //ZYUC_GRAMMERREWRITE_H
#pragma once
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;
class GetGrammerByCsv{
    string start;
    set<string> symboal;
    map<string,vector<string>> production;
public:
    map<string,vector<string>> ReadGrammer(string path);
    map<string,vector<string>> ReWriteGrammer(map<string,vector<string>> production);
    void EliminateDirect();
    GetGrammerByCsv(string _start){
        start=_start;
    };
    void EliminateInDirect();
    void dfs(vector<vector<string>> &pro,vector<vector<string>>::iterator &iter,vector<string> &result,string curstring);
    void clear();
    void show();
    void showproduction();
    map<string,vector<string>> getProduction(){return production;}
};
