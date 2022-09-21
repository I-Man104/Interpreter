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

string AppendEOF(string s);


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
//class SeenLexer::

struct Token {
	int Type;
	string Lexeme;
	bool IS(string lexeme);
	bool IS(int type);

};

#endif // !__LEXER_H-_