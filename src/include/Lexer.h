#pragma once

#include "../include/TokenTypes.h"
#include "llvm/ADT/PointerSumType.h"
#include "llvm/Support/MemoryBuffer.h"
class Lexer {
  const char *bufferStart;
  const char *bufferPtr;

public:
  Lexer(const llvm::StringRef &buffer) {
    bufferStart = buffer.begin();
    bufferPtr = buffer.begin();
  }
  void next(token::Token &token);

private:
  // consturcts token
  void formToken(token::Token &resault, const char *tokenEnd, token::Type type);
  // returns char at bufferPtr+1 addres
  inline const char peek() const { return *(bufferPtr + 1); }
  // returns true if ch == *(bufferPtr + 1)
  inline bool peekCheck(char ch) const { return (*(bufferPtr + 1) == ch); }
};
