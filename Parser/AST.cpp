//
// Created by 风格福德宫 on 2022/5/3.
//

#include "AST.h"
#include "BaseVisitor.h"
void VariableAST::accept(Visitor *visitor) {
    visitor->visit(this);
}

void NumAST::accept(Visitor *visitor) {
    visitor->visit(this);
}
void BinOpAST::accept(Visitor *visitor) {
    visitor->visit(this);
}

void AssginAST::accept(Visitor *visitor) {
    visitor->visit(this);
}

void IfAST::accept(Visitor *visitor) {
    visitor->visit(this);
}

void WhileAST::accept(Visitor *visitor) {
    visitor->visit(this);
}
