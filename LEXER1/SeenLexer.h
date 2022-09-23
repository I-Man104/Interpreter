#pragma once
#ifndef __SEEN_LEXER_H__
#define __SEEN_LEXER_H__
#include "Lexer.h"

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

class SeenLexer : public AbstractLexer
{
public:
	SeenLexer();
	virtual int SwitchState(char c, int state, int acceptType);

	int DoStateReady(char c, int state, int& typeToAccept);
	int DoState1(char c, int state, int& typeToAccept);
	int DoState2(char c, int state, int& typeToAccept);
	int DoState3(char c, int state, int& typeToAccept);
	int DoState4(char c, int state, int& typeToAccept);
	int DoState5(char c, int state, int& typeToAccept);

};
#endif