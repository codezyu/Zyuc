cmake_minimum_required(VERSION 3.21)
project(ZyuC)

set(CMAKE_CXX_STANDARD 14)
set( CMAKE_BUILD_TYPE "Debug" )
add_executable(ZyuC main.cpp Lexer/lexer.h Lexer/lexer.cpp Parser/GrammerReWrite.h Parser/GrammerReWrite.cpp tool.h Parser/Lab2Grammer.cpp Parser/Lab2Grammer.h Parser/SymbolTable.cpp Parser/SymbolTable.h Parser/AST.h Parser/BaseAST.h Parser/BaseVisitor.h Parser/Visitor.h Parser/Visitor.cpp Parser/AST.cpp)
