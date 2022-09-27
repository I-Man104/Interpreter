#pragma once
#ifndef __PARSER_H__
#define __PARSER_H__
#include "Lexer.h"
class Parser
{
};

class Expression
{
};

class ArgList
{
};

class BindList
{
};

class ParamList
{
};
//match????????????????????????
void Match(string lexeme);
void Match(int token);
//handling parameters
ArgList* Args();
BindList* Bindings();
ParamList* Params();
//parametes needed
Expression* FuncApplication(Expression* t, ArgList* args);
Expression* LetExpression(Expression* t, BindList* lst);
Expression* FunctionExpression(Expression* t, ParamList* lst);
Expression* IfExpression(Expression* condition, Expression* thenExp, Expression* elseExp);
//IDK
Expression* Expr();
Expression* IntLiteral(int val);
Expression* StrLiteral(string val);
//doing operations
Expression* BinaryPrimitive(string s, Expression* t, Expression* t2); //???

#endif