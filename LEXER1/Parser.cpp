#include "Parser.h"
void Match(int type) {
	if (Lookahead->Type == type) {
		AbstractLexer c;
		Lookahead = c.NextToken();
	}
	else {
		throw new LexerException("Error");
	}
}
void Match(string lexeme) {
	if (Lookahead->Lexeme == lexeme) {
		AbstractLexer c;
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

Expression* Expression::BinaryPrimitive(string op, Expression* t, Expression* t2) {
	t->operation = op;
	t->Term1 = t;
	t->Term2 = t2;
	return t;
}
