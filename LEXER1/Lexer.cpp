#include "Lexer.h"
#include<iostream>
#include<string>

using namespace std;

string AppendEOF(string s)
{
	return s + " EOF";
}

bool Token::IS(string lexeme)
{
	return Lexeme == lexeme;
}
bool Token::IS(int type)
{
	return Type == type;
}

AbstractLexer::AbstractLexer()
{

}
void AbstractLexer::Init(string input)
{
	_input = AppendEOF(input);
	_p1 = _p2 =0;
	_state = STATE_READY;
}

bool AbstractLexer::HasMoreTokens()
{
	return _p1 < _input.length() - 1;
}

Token *AbstractLexer::NextToken()
{
	char c;
	int acceptType;
	while (_p2 < _input.length())
	{
		c = Read();
		_state = SwitchState(c, _state, acceptType);
		if (_state == STATE_ACCEPT)
		{
			Token* t = Accept(acceptType);
			if (t->Type != TOKEN_SKIP)
				return t;

		}
		
		if (_state == STATE_READY)
		{
			Token* t = new Token();
			t->Lexeme = "";
			t->Type = TOKEN_EOF; //////
			return t;
		}
		else
		{
			throw new LexerException("End Of Input");
		}
	}
}

char AbstractLexer::Read()
{
	char c = _input[_p2];
	_p2++;
	return c;
}

void AbstractLexer::Retract()
{
	_p2--;
}

void AbstractLexer::Reset()
{
	_p2 = _p1;
}

Token *AbstractLexer::Accept(int type)
{
	string lexeme = _input.substr(_p1, _p2); //accept str between 2 ptrs
	_p1 = _p2;
	Token* ret = new Token();
	ret->Lexeme = lexeme;
	ret->Type = type;
	_state = STATE_READY;
	return ret;

}

LexerException::LexerException(string msg)
{
	Message = msg;
}

void AbstractLexer::Error(string message)
{
	throw new LexerException(message);

}
