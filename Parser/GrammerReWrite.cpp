//
// Created by 风格福德宫 on 2022/4/21.
//
#include "GrammerReWrite.h"
#include <fstream>
#include <sstream>
#include <iostream>

map<string, vector<string>> GetGrammerByCsv::ReadGrammer(string path) {
    ifstream csv(path);
    map<string,vector<string>> ProMap;
    if(csv.good()){
        string line;
        while (getline(csv,line)){
            istringstream readstr(line);
            string key;
            string value;
            getline(readstr,key,',');
            getline(readstr,value);
            if(ProMap.count(key)==0){
                vector<string> valueArray;
                symboal.insert(key);
                ProMap[key]=valueArray;
            }
            ProMap[key].push_back(value);
        }
    }
    production=ProMap;
        return ProMap;
}

map<string, vector<string>> GetGrammerByCsv::ReWriteGrammer(map<string, vector<string>> production) {
    if(production.empty())
        return production;
    else{
        EliminateDirect();
        clear();
    }
    return production;
}

void GetGrammerByCsv::EliminateDi   rect() {
    for(set<string>::iterator iter=symboal.begin();iter!=symboal.end();iter++){
        vector<string> value=production[*iter];
        int status=0;
        string newSymbol=*iter;
        while(symboal.count(newSymbol)){
            newSymbol+=*iter;
        }
        vector<string> fore;
        vector<string> back;
        for(vector<string>::iterator inneriter=value.begin();inneriter!=value.end();inneriter++)
        {
            string newWord="";
            stringstream ss(*inneriter);
            string word;
            ss>>word;
            if(word==*iter)
            {
                status=1;
                while(ss>>word){
                    newWord+=word+" ";
                }
                newWord+=" "+newSymbol;
                back.emplace_back(newWord);
            }
            else{
                newWord+=word;
                while(ss>>word){
                    newWord+=" "+word;
                }
                newWord+=" "+newSymbol;
                fore.emplace_back(newWord);
            }

        }
        if(status){
            back.emplace_back("\e");
            production[*iter]=fore;
            production[newSymbol]=back;
            symboal.insert(newSymbol);
        }

    }
}
void GetGrammerByCsv::EliminateInDirect() {
    for(set<string>::iterator iter=symboal.begin();iter!=symboal.end();iter++) {
        for(set<string>::iterator inner=symboal.begin();inner!=iter;inner++) {
            vector<string> value=production[*iter];
            vector<string> newproduction;
            for(vector<string>::iterator inneriter=value.begin();inneriter!=value.end();inneriter++)
            {
                vector<vector<string>> newpro;
                stringstream ss(*inneriter);
                string word="";
                while(ss>>word) {
                    if (word == *inner) {
                        vector<string> temp=production[*inner];
                        newpro.emplace_back(temp);
                    }
                    else{
                        vector<string> temp;
                        temp.emplace_back(word);
                        newpro.emplace_back(temp);
                    }
                }
                vector<vector<string>>::iterator myiter=newpro.begin();
                dfs(newpro,myiter,newproduction,"");
            }
            set<string>s(newproduction.begin(),newproduction.end());
            newproduction.assign(s.begin(),s.end());
            vector<string>().swap(production[*iter]);
            vector<string>().swap(value);
            production[*iter].swap(newproduction);
        }
    }
}
void GetGrammerByCsv::dfs(vector<vector<string>> &pro,vector<vector<string>>::iterator &iter,vector<string> &result,string curstring){
    if(iter==pro.end()){
            result.emplace_back(curstring);
            return;
    }
    for(vector<string>::iterator inner=iter->begin();inner!=iter->end();inner++) {
        vector<vector<string>>::iterator newiter=iter+1;
        dfs(pro, newiter, result, curstring +" "+*inner);
    }
}

void GetGrammerByCsv::clear() {
    map<string,int>status;
    for(set<string>::iterator iter=symboal.begin();iter!=symboal.end();iter++) {
        status[*iter]=0;
        vector<string> value=production[*iter];
        for(vector<string>::iterator inneriter=value.begin();inneriter!=value.end();inneriter++){
            vector<vector<string>> newpro;
            stringstream ss(*inneriter);
            string word="";
            while(ss>>word) {
                if(symboal.count(word)){
                    status[word]=1;
                }
            }
        }
    }
    for(map<string,int>::iterator iter=status.begin();iter!=status.end();iter++){
        if(iter->second==0){
            symboal.erase(iter->first);
            production.erase(iter->first);
        }
    }
}
void GetGrammerByCsv::show() {
    for(set<string>::iterator iter=symboal.begin();iter!=symboal.end();iter++) {
        cout<<*iter<<endl;
    }
}
void GetGrammerByCsv::showproduction() {
    for(map<string,vector<string>>::iterator iter=production.begin();iter!=production.end();iter++){
        cout<<iter->first<<"->";
        for(vector<string>::iterator inner=iter->second.begin();inner!=iter->second.end();inner++){
            cout<<*inner;
            if(inner!=iter->second.end()-1)
                cout<<"|";
        }
        cout<<endl;
    }
}