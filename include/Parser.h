#pragma once
#include "Lexer.h"
#include "AST.h"
#include "llvm/Support/raw_ostream.h"
class Parser {
  Lexer &lex;
  Token token;
  bool caughtError;

  void error() { llvm::errs() << "Unexpected: " << token.GetText() << "\n"; }
  void advance() { lex.next(token); }
  bool expect(Token::TokenType type) {
    if (type != token.GetType()) {
      error();
      return true;
    }
    return false;
  }
  bool consume(Token::TokenType type){
	if(expect(type)){
		return true;
	}
	advance();
	return false;
  }

  AST* parseCalc();
  Expr* parseExpr();
  Expr* parseTerm();
  Expr* parseFactor();
};
