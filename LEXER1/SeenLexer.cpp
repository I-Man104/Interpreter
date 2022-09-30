#include "SeenLexer.h"
#include<string>
using namespace std;

SeenLexer::SeenLexer() :AbstractLexer() {};

int SeenLexer::SwitchState(char c, int state, int typeToAccept) {
	switch (state)
	{
	case STATE_READY:
		return DoStateReady(c, state, typeToAccept);
	case 1:
		return DoState1(c, state, typeToAccept);
	case 2:
		return DoState2(c, state, typeToAccept);
	case 3:
		return DoState3(c, state, typeToAccept);
	case 4:
		return DoState4(c, state, typeToAccept);
	case 5:
		return DoState5(c, state, typeToAccept);
	default:
		throw new LexerException(string("Unknown char"));
	}
} //int
int SeenLexer::DoStateReady(char c, int state, int& typeToAccept) {
	if (isalpha(c)) state = 1;
	else if (isdigit(c)) state = 2;
	else if (c == '"') state = 3;
	else if (c == '=') state = 4;
	else if (c == ' ' || c == '\r' || c == '\n') state = 5;

	else if (c == '&') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_ANDING;
	}
	else if (c == '|') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_ORING;
	}
	else if (c == '(') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_LPAREN;
	}
	else if (c == ')') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_RPAREN;
	}
	else if (c == '{') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_LBRACE;
	}
	else if (c == '}') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_RBRACE;
	}
	else if (c == '+' || c == '-' || c == '*' || c == '/') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_OPERATOR;
	}
	else if (c == ',') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_COMMA;
	}
	else if (c == '<') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_LESS_THAN;
	}
	else if (c == '>') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_GREATER_THAN;
	}
	else if (c == 'if') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_IF;
	}
	else if (c == 'else') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_ELSE;
	}
	else if (c == 'func') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_FUNC;
	}
	else if (c == 'let') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_LET;
	}
	else if (c == 'in') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_IN;
	}
	return state;
}
int SeenLexer::DoState1(char c, int state, int& typeToAccept) {
	if (isalpha(c) || isdigit(c)) state = 1;
	else {
		Retract();
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_IDENTIFIER;
	}
	return state;
}

int SeenLexer::DoState2(char c, int state, int& typeToAccept) {
	if (isdigit(c)) state = 2;
	else {
		Retract();
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_INT_LITERAL;
	}
	return state;
}

int SeenLexer::DoState3(char c, int state, int& typeToAccept) {
	if (c == '"') {
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_STRING_LITERAL;
	}
	return state;
}

int SeenLexer::DoState4(char c, int state, int& typeToAccept) {
	if (c == '=') {
		Retract();
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_EQUALITY_OPERATOR;
	}
	else {
		Retract();
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_BINDING;
	}
	return state;
}

int SeenLexer::DoState5(char c, int state, int& typeToAccept) {
	if (c == ' ' || c == '\r' || c == '\n')state = 5;
	else {
		Retract();
		state = STATE_ACCEPT;
		typeToAccept = TOKEN_SKIP;
	}
	return state;
}