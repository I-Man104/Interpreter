#pragma once
#ifndef __LEXER_H__
#define __LEXER_H__
#include <iostream>
#include <string>
using namespace std;

const int STATE_READY = -1;
const int STATE_ACCEPT = -2;
const int STATE_FAIL = -3;

const int TOKEN_SKIP = -1;
const int TOKEN_EOF = -2;

const int TOKEN_INT_LITERAL = 0;
const int TOKEN_STRING_LITERAL = 1;
const int TOKEN_IDENTIFIER = 2;
const int TOKEN_LPAREN = 3;
const int TOKEN_RPAREN = 4;
const int TOKEN_LBRACE = 5;
const int TOKEN_RBRACE = 6;
const int TOKEN_OPERATOR = 7;
const int TOKEN_COMMA = 8;
const int TOKEN_BINDING = 9;
const int TOKEN_EQUALITY_OPERATOR = 10;
const int TOKEN_LESS_THAN = 11;
const int TOKEN_GREATER_THAN = 12;
const int TOKEN_ANDING = 13;
const int TOKEN_ORING = 14;
const int TOKEN_IF = 15;
const int TOKEN_ELSE = 16;
const int TOKEN_FUNC = 17;
const int TOKEN_LET = 18;
const int TOKEN_IN = 19;
const int TOKEN_LETREC = 20;

string AppendEOF(string s);


struct Token {
	int Type;
	string Lexeme;
	bool IS(string lexeme);
	bool IS(int type);
};

class AbstractLexer
{
	string _input;
	unsigned int _p1, _p2;
	int _state;
public:
	AbstractLexer();
	void Init(string input);
	bool HasMoreTokens();
	Token *NextToken();
protected:
	virtual int SwitchState(char c, int state, int acceptType);
	char Read();
	void Retract();
	void Reset();
	Token *Accept(int Type);
	void Error(string message);
};
class LexerException
{
	string Message;
public:
	LexerException(string msg);
};
#endif // !__LEXER_H-_