#pragma once
#ifndef __SEEN_LEXER_H__
#define __SEEN_LEXER_H__
#include "Lexer.h"

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