#pragma once
#ifndef __PARSER_H__
#define __PARSER_H__
#include "Lexer.h"
#include<vector>
class Parser
{
};

class Expression {
public:
	vector<Expression*>expressions;
};

class ParamList //formals
{
public:
	ParamList* Params();
private:
	vector<Token> list;
};

class BindList
{
public:
	BindList* Bindings();
private:
	vector<Expression*> _bindLst;
};

class ArgList
{
public:
	ArgList* Args();
private:
	vector<Expression*> _argLst;
};

class Binary:public Expression
{
public:
	Expression* BinaryPrimitive(string op, Binary* t, Binary* t2);
private:
	string operation;
	Expression* Term1;
	Expression* Term2;
};

Token* Lookahead;
void Match(string s);
void Match(int token);

class IntLit : public Expression
{
public:
	Expression* IntLiteral(int val);
private:
	int intVal;
};

class StrLit :public Expression
{
public:
	Expression* StrLiteral(string val);
private:
	string StrVal;
};

class Expr : public Expression
{
private:
	Expression* expr();
};

class IF :public Expression {
public:
	void IfExpression(Expression*, Expression*, Expression*);
private:
	Expression* condition;
	Expression* thenPart;
	Expression* elsePart;
};

class funcExp :public Expression {
public:
	void FunctionExpression(Expression*, ParamList*);
private:
	Expression* expression;
	ParamList* list;
};

class funcCall : public Expression {
public:
	void FuncApplication(Expression*, ArgList*);
private:
	Expression* expression;
	ArgList* args;
};

class LetExpr : public Expression
{
public:
	void LetExpression(Expression*, BindList*);
private:
	Expression* _t;
	BindList* _lst;
};
AbstractLexer c;

#endif