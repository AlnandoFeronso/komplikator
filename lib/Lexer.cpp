#include "Lexer.h"
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/Compiler.h>

namespace charhelper {
LLVM_READNONE inline bool isWhitespace(char c) {
  return c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r' ||
         c == '\n';
}
LLVM_READNONE inline bool isDigit(char c) { return c >= '0' && c <= '9'; }
LLVM_READNONE inline bool isLetter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
} // namespace charhelper

void Lexer::next(Token &token) {
  while (*bufferPtr && charhelper::isWhitespace(*bufferPtr)) {
    bufferPtr++;
  }
  if (*bufferPtr == 0) {
    token.type = Token::eoi;
    return;
  }

  if (charhelper::isLetter(*bufferPtr)) {
    const char *end = bufferPtr + 1;
    while (charhelper::isLetter(*end))
      end++;
    llvm::StringRef word(bufferPtr, end - bufferPtr);
    Token::TokenType type;
    if (word == "with") {
      type = Token::KW_with;
    } else {
      type = Token::ident;
    }
    formToken(token, end, type);
  } else if (charhelper::isDigit(*bufferPtr)) {
    const char *end = bufferPtr + 1;
    while (charhelper::isDigit(*end))
      end++;
    formToken(token, end, Token::number);
  } else {
    switch (*bufferPtr) {
    case '+':
      formToken(token, bufferPtr + 1, Token::plus);
      break;
    case '-':
      formToken(token, bufferPtr + 1, Token::minus);
      break;
    case '*':
      formToken(token, bufferPtr + 1, Token::star);
      break;
    case '/':
      formToken(token, bufferPtr + 1, Token::slash);
      break;
    case '(':
      formToken(token, bufferPtr + 1, Token::l_paren);
      break;
    case ')':
      formToken(token, bufferPtr + 1, Token::r_paren);
      break;
    case ':':
      formToken(token, bufferPtr + 1, Token::colon);
      break;
    case ',':
      formToken(token, bufferPtr + 1, Token::comma);
      break;
    default:
      formToken(token, bufferPtr + 1, Token::invalid);
    }
    return;
  }
}

void Lexer::formToken(Token &resault, const char *tokenEnd,
                      Token::TokenType type) {
  resault.type = type;
  resault.text = llvm::StringRef(bufferPtr, tokenEnd - bufferPtr);

  bufferPtr = tokenEnd;
  return;
}
