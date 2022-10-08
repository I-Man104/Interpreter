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
Expression* IntLit::IntLiteral(int val)
{
	IntLit* t;
	t->intVal = val;
	return t;
}

Expression* StrLit::StrLiteral(string val)
{
	StrLit* t;
	t->strVal = val;
	return t;
}
/*
Expression* Expr::expr(string op, Expression* _t1, Expression* _t2)
{
	Expr* t;
	t->operation = op;
	t->Term1 = _t1;
	t->Term2 = _t2;
	return t;

}*/
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

Expression* LetExpr::LetExpression(Expression* t, BindList* lst)
{
	LetExpr* T;
	BindList* lst = Bindings();
	T->_t = t;

	return T;
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
BindList* BindList::Bindings()
{
}

ArgList* ArgList::Args()
{
	Match(TOKEN_LPAREN);
		while (true)
		{
			this->_argLst.push_back(*c.NextToken);
			Match(TOKEN_COMMA);
			if (Lookahead->Type == TOKEN_RPAREN) break;
		}
		Match(TOKEN_RPAREN);
		return this;
}

