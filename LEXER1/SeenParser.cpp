#include "SeenParser.h"
Expression* SeenParser::ArithmeticExpr() {
	Binary* t = (Binary*)Term();
	while (Lookahead->IS("+") || Lookahead->IS("-")) {
		string theOperator = Lookahead->Lexeme;
		Match(Lookahead->Lexeme);
		Binary* t2 = (Binary*)Term();
		t->BinaryPrimitive(theOperator, t, t2);
	}
	return t;
 }
Expression* SeenParser::Term() {
	Binary* t =(Binary*)Primary();
	while (Lookahead->IS("*") || Lookahead->IS("/")) {
		string theOperator = Lookahead->Lexeme;
		Match(Lookahead->Lexeme);
		Binary* t2 = (Binary*)Primary();
		t->BinaryPrimitive(theOperator, t, t2);
	}
	return t;
}
Expression* SeenParser::Primary() {
	funcCall* t =(funcCall*) PrimaryNonApplication();
	while (Lookahead->IS(TOKEN_LPAREN)) {
		ArgList* args = args->Args();
		t->FuncApplication(t, args);
	}
	return t;
}

Expression* SeenParser::PrimaryNonApplication() {
	if (Lookahead->IS(TOKEN_LPAREN)) {
		Expression* t;
		Match(TOKEN_LPAREN);
		t = Expr();
		Match(TOKEN_RPAREN);
		return t;
	}
	if (Lookahead->IS(TOKEN_INT_LITERAL)) {
		IntLit* t;
		int value = atoi(Lookahead->Lexeme.c_str());
		Match(TOKEN_INT_LITERAL);
		t->IntLiteral(value);
		return t;
	}
	if (Lookahead->IS(TOKEN_STRING_LITERAL)) {
		StrLit* t;
		string value = Lookahead->Lexeme;
		Match(TOKEN_STRING_LITERAL);		
		t->StrLiteral(value);
		return t;
	}
	if (Lookahead->IS(TOKEN_LET)) {
		LetExpr* t;
		Expression* exp;
		BindList* lst;
		Match(TOKEN_LET);
		lst->Bindings();
		Match(TOKEN_IN);
		Match(TOKEN_LBRACE);
		exp = Expr();
		Match(TOKEN_RBRACE);
		t->LetExpression(exp, lst);
		return t;
	}
	if (Lookahead->IS(TOKEN_FUNC)) {
		funcExp* t;
		Match(TOKEN_FUNC);
		ParamList* lst = lst->Params();
		Match(TOKEN_LBRACE);
		Expression* exp = Expr();
		Match(TOKEN_RBRACE);
		t->FunctionExpression(exp, lst);
		return t;
	}
	if (Lookahead->IS(TOKEN_IF)) {
		IF* t;
		Match(TOKEN_IF);
		Match(TOKEN_LPAREN);
		Expression* condition = Expr();
		Match(TOKEN_RPAREN);
		Match(TOKEN_LBRACE);
		Expression* thenExp = Expr();
		Match(TOKEN_RBRACE);
		Match(TOKEN_ELSE);
		Match(TOKEN_LBRACE);
		Expression* elseExp = Expr();
		Match(TOKEN_RBRACE);
		t->IfExpression(condition, thenExp, elseExp);
		return t;
	}
}

Expression* SeenParser::Expr() {
	while (true) {
		this->expressions.push_back(PrimaryNonApplication());
		if (Lookahead->Type == TOKEN_RBRACE || Lookahead->Type == TOKEN_RPAREN)break;
		Match(TOKEN_COMMA);
	}
	return this;
}