#pragma once

#include "../include/TokenTypes.h"
#include "llvm/ADT/PointerSumType.h"
#include "llvm/Support/MemoryBuffer.h"
class Lexer;

class Token {
  friend Lexer;

public:

private:
  TokenType type;
  llvm::StringRef text;

public:
  TokenType GetType() const { return type; }
  llvm::StringRef GetText() const { return text; }

  bool is(TokenType t) const { return t == type; }
  bool isOneOf(TokenType t1, TokenType t2) {
    return (t1 == type || t2 == type);
  };
  template <typename... T>
  bool isOneOf(TokenType t1, TokenType t2, T... ts) const {
    return is(t1) || isOneOf(t2, ts...);
  }
};
class Lexer {
  const char *bufferStart;
  const char *bufferPtr;

public:
  Lexer(const llvm::StringRef &buffer) {
    bufferStart = buffer.begin();
    bufferPtr = buffer.begin();
  }
  void next(Token &token);

private:
  void formToken(Token &resault, const char *tokenEnd, TokenType type);
};
