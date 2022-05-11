//
// Created by 风格福德宫 on 2022/4/21.
//
#pragma once
#ifndef ZYUC_LEXER_H
#define ZYUC_LEXER_H
#endif //ZYUC_LEXER_H
#include <regex>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
const string TYPE = "^(int|double|float|char|class|struct)";
const string INTNUMBER = "^((\\+|-)?(\\d+|(0(o|O)[0-7]+)|(0(x|X)[0-9A-Fa-f]+)))";
const string DOUBLENUM = "(\\+|-)?((\\d+\\.\\d*)|\\.\\d+|0(o|O)([0-7]+\\.[0-7]*|\\.[0-7]*)|0(x|X)([0-9A-Fa-f]+\\.[0-9A-Fa-f]*|\\.[0-9A-Fa-f]*))";
const string IDENTIFILIER = "^([a-zA-Z_][a-zA-Z_\\d]*)";
const string KeyWordPattern = "^(if|else|switch|case|while|for|do|then)";
const string OperatorPattern = "\\(|\\)|(->)|(\\+\\+|--)|(\\|\\||&&)|((\\+|-|\\*|/|%|=|&|\\||\\^|<<|>>|<|>|=|!)=?)|(\\?|:|,|;)|::";
const string ComandPattern = "^(#\\S+)";
const vector<string> TokenTypeName={
        "IF",
        "WHILE",
        "INT",
        "PLUS",
        "GREATER",
        "LESSER",
        "END",
        "LEFTBRACKET",
        "RIGHTBRACKET",
        "DO",
        "MINUS",
        "THEN",
        "REAL",
        "MULTIPLY",
        "DIVISION",
        "IDNETIFIER",
        "CONSTANT",
        "STRINGCONSTANT",
        "INTTYPE",
        "REALTYPE",
        "ASSIGNMENT",
        "ELSE",
        "EQUAL"
};
enum TokenType{
    IF,
    WHILE,
    INT,
    PLUS,
    GREATER,
    LESSER,
    END,
    LEFTBRACKET,
    RIGHTBRACKET,
    DO,
    MINUS,
    THEN,
    REAL,
    MULTIPLY,
    DIVISION,
    IDNETIFIER,
    CONSTANT,
    STRINGCONSTANT,
    INTTYPE,
    REALTYPE,
    ASSIGNMENT,
    ELSE,
    EQUAL
};
class Token{
public:
    TokenType type;
    union Value{
        string stringval;
        int* intval;
        double* doubleval;
    public:
        Value(){
            new(&stringval) string ;
        }
        ~Value(){
            stringval.~string();
        }
    }value;
public:
    Token(TokenType _type,string _value) :type(_type){
        value.stringval=_value;
    };
    Token(TokenType _type,int* _value) :type(_type){
        value.intval=_value;
    };
    Token(TokenType _type,double* _value) :type(_type){
        value.doubleval=_value;
    };
    Token(){}
};
class Lexer{
public:
    vector<Token*> tokenList;
    vector<string> errorList;
    std::istream &input;
public:
    void scan();
    Lexer(std::istream &_inputStream): input(_inputStream){
    }
    void show();
};

