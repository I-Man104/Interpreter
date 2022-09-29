#pragma once
#ifndef __SEEN_PARSER_H__
#define __SEEN_PARSER_H__
#include "Parser.h"
class SeenParser:Parser
{
	Token* Lookahead;
	Expression* ArithmeticExpr();
	Expression* Term();
	Expression* Primary();
	Expression* PrimaryNonApplication();
};
#endif