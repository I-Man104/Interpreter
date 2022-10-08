#include "Parser.h"
void Match(int type) {
	if (Lookahead->Type == type) {
		Lookahead = c.NextToken();
	}
	else {
		throw new LexerException("Error");
	}
}
void Match(string lexeme) {
	if (Lookahead->Lexeme == lexeme) {
		Lookahead = c.NextToken();
	}
	else {
		throw new LexerException("Error");
	}
}

Expression* IF::IfExpression(Expression* cond, Expression* thenExp, Expression* elseExp) {
	IF* t;
	t->condition = cond;
	t->thenPart = thenExp;
	t->elsePart = elseExp;
	return t;
}

Expression* Binary::BinaryPrimitive(string op, Binary* t, Binary* t2) {
	t->operation = op;
	t->Term1 = t;
	t->Term2 = t2;
	return t;
}

void funcExp::FunctionExpression(Expression* exp, ParamList* lst) {
	this->expression = exp;
	this->list = lst;
}

ParamList* ParamList::Params() {
	Match(TOKEN_LPAREN);
	while (true) {
		this->list.push_back(*c.NextToken());
		Match(TOKEN_COMMA);
		if (Lookahead->Type == TOKEN_RPAREN)break;
	}
	Match(TOKEN_RPAREN);
	return this;
}
