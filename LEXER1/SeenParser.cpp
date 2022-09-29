#include "SeenParser.h"
Expression* SeenParser::ArithmeticExpr() {
	Expression* t = Term();
	while (Lookahead->IS("+") || Lookahead->IS("-")) {
		string theOperator = Lookahead->Lexeme;
		Match(Lookahead->Lexeme);
		Expression* t2 = Term();
		// t = new BinaryPrimitive(theOperator, t, t2);
		t = BinaryPrimitive(theOperator, t, t2);
	}
	return t;
 }
Expression* SeenParser::Term() {
	Expression* t = Primary();
	while (Lookahead->IS("*") || Lookahead->IS("/")) {
		string theOperator = Lookahead->Lexeme;
		Match(Lookahead->Lexeme);
		Expression* t2 = Primary();
		// t = new BinaryPrimitive(theOperator, t, t2);
		t = BinaryPrimitive(theOperator, t, t2);
	}
	return t;
}
Expression* SeenParser::Primary() {
	Expression* t = PrimaryNonApplication();
	while (Lookahead->IS("(")) {
		ArgList* args = Args();
		//t = new FuncApplication(t, args);
		t = FuncApplication(t, args);
	}
	return t;
}
Expression* SeenParser::PrimaryNonApplication() {
	Expression* t = NULL;
	if (Lookahead->IS("(")) {
		Match("(");
		t = Expr();
		Match(")");
		return t;
	}
	if (Lookahead->IS(TOKEN_INT_LITERAL)) {
		int value = atoi(Lookahead->Lexeme.c_str());
		Match(TOKEN_INT_LITERAL);
		//t = new IntLiteral(value);
		t = IntLiteral(value);
		return t;
	}
	if (Lookahead->IS(TOKEN_STRING_LITERAL)) {
		string value = Lookahead->Lexeme;
		Match(TOKEN_STRING_LITERAL);
		//t = new StrLiteral(value);
		t = StrLiteral(value);
		return t;
	}
	if (Lookahead->IS("let")) {
		Match("let");
		BindList* lst = Bindings();
		Match("in");
		//t = new LetExpression(t, lst);
		t = LetExpression(t, lst);
		return t;
	}
	if (Lookahead->IS("func")) {
		Match("func");
		ParamList* lst = Params();
		Match("(");
		Expression* exp = Expr();
		Match(")");
		//t = new FunctionExpression(t, lst);
		t = FunctionExpression(t, lst);
		return t;
	}
	if (Lookahead->IS("if")) {
		Match("if");
		Match("(");
		Expression* condition = Expr();
		Match(")");
		Match("{");
		Expression* thenExp = Expr();
		Match("}");
		Match("else");
		Match("{");
		Expression* elseExp = Expr();
		Match("}");
		//t = new ifExpression(condition, thenExp, elseExp);
		t = IfExpression(condition, thenExp, elseExp);
		return t;
	}
}