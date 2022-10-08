#pragma once
#ifndef __PARSER_H__
#define __PARSER_H__
#include "Lexer.h"
#include<vector>
class Parser
{
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
	vector<Token> _bindLst;
}
class ArgList
{
public:
	ArgList* Args();
private:
	vector<Token> _argLst;
};



class Expression {

};

class Binary:Expression
{
public:
	Expression* BinaryPrimitive(string op, Binary* t, Binary* t2);
private:
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


class funcExp :public Expression {
public:
	void FunctionExpression(Expression*, ParamList*);
private:
	Expression* expression;
	ParamList* list;
};

Token* Lookahead;
//SUPER GIGA GEEEEK AYMOOOON!!!!!!!!!!!!!!!!!
void Match(string s);
void Match(int token);

//FATMAAAAAAAAAAAAAAÚ
/////////////Expression* IntLiteral(int val);
//////////////Expression* StrLiteral(string val);
///Expression* Expr();
///Expression* LetExpression(Expression* t, BindList* lst);
//______________________________
//for calling a function
Expression* FuncApplication(Expression* t, ArgList* args);
//______________________________

class IntLit : public Expression
{
public:
	int intVal;
private:
	Expression* IntLiteral(int val);

};

class StrLit :public Expression
{
public:
	string StrVal;
private:
	Expression* StrLiteral(string val);

};

class Expr : public Expression
{
private:
	Expression* expr();

};
class LetExpr : public Expression
{
public:
	Expression* LetExpression(Expression* t, BindList* lst);
private:
	Expression* _t;
	BindList* _lst;



};
AbstractLexer c;

#endif