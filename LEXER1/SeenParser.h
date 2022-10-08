#pragma once
#ifndef __SEEN_PARSER_H__
#define __SEEN_PARSER_H__
#include "Parser.h"
class SeenParser:public Expression
{
	Expression* ArithmeticExpr();
	Expression* Term();
	Expression* Primary();
	Expression* PrimaryNonApplication();
	Expression* Expr();
};

#endif