#pragma once
#include "AST.h"
#include "Lexer.h"
#include "TokenTypes.h"
#include "llvm/Support/raw_ostream.h"
#include <memory>
class Parser {
  Lexer &lex;
  token::Token token;
  bool caughtError;

  bool expect(token::Type);
  bool consume(token::Type);
  void advance();
  

  bool parseSimpleExpression() = delete;
  bool parseInclude() = delete;
  bool parseDeclarations() = delete;
  bool parseConstantDeclarations() = delete;
  bool parseTerm() = delete;
  bool parseExpression() = delete;
  
  std::unique_ptr<ModuleDeclaration> parse();

};
