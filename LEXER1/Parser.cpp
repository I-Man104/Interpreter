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
	t->StrVal = val;
	return t;
}

Expression* Binary::BinaryPrimitive(string op, Binary* t, Binary* t2) {
	t->operation = op;
	t->Term1 = t;
	t->Term2 = t2;
	return t;
}

void IF::IfExpression(Expression* cond, Expression* thenExp, Expression* elseExp) {
	this->condition = cond;
	this->thenPart = thenExp;
	this->elsePart = elseExp;
}

void LetExpr::LetExpression(Expression* t, BindList* lst)
{
	this->_t = t;
	this->_lst = lst;
}

void funcExp::FunctionExpression(Expression* exp, ParamList* lst) {
	this->expression = exp;
	this->list = lst;
}

void funcCall::FuncApplication(Expression* exp, ArgList* args) {
	this->expression = exp;
	this->args = args;
}

//FUNC EXP
ParamList* ParamList::Params() {
	Match(TOKEN_LPAREN);
	while (true) {
		this->list.push_back(*c.NextToken());
		if (Lookahead->Type == TOKEN_RPAREN)break;
		Match(TOKEN_COMMA);
	}
	Match(TOKEN_RPAREN);
	return this;
}
//LET EXP
BindList* BindList::Bindings()
{
	BindList* t;
	Match(TOKEN_LPAREN);
	t->_bindLst = Expr().expressions;
	Match(TOKEN_RPAREN);
	return t;
}
//FUNC CALL
ArgList* ArgList::Args()
{
	ArgList* t;
	Match(TOKEN_LPAREN);
	t->_argLst = Expr().expressions;
	Match(TOKEN_RPAREN);
	return t;
}