#pragma once
#ifndef __PARSER_H__
#define __PARSER_H__
#include "Lexer.h"

class Parser
{
};

class Expression
{
public:
	Expression* BinaryPrimitive(string op, Expression* t, Expression* t2);
	string operation;
	Expression* Term1;
	Expression* Term2;
};

class IF:public Expression {
public:
	Expression* IfExpression(Expression* condition, Expression* thenExp, Expression* elseExp);
private:
	Expression* condition;
	Expression* thenPart;
	Expression* elsePart;
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
Token* Lookahead;
//SUPER GIGA GEEEEK AYMOOOON!!!!!!!!!!!!!!!!!
void Match(string s);
void Match(int token);
//for creating a function
Expression* FunctionExpression(Expression* t, ParamList* lst);
//doing operations

//FATMAAAAAAAAAAAAAAÚ
Expression* IntLiteral(int val);
Expression* StrLiteral(string val);
Expression* Expr();
Expression* LetExpression(Expression* t, BindList* lst);
//______________________________
//for calling a function
Expression* FuncApplication(Expression* t, ArgList* args);
//______________________________

//Later
ArgList* Args();
BindList* Bindings();
ParamList* Params();

#endif