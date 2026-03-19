#include "../include/Lexer.h"
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

void Lexer::next(token::Token &token) {
  while (*bufferPtr && charhelper::isWhitespace(*bufferPtr)) {
    bufferPtr++;
  }
  if (*bufferPtr == 0) {
    token.type = token::TOK_EOF;
    return;
  }

  if (charhelper::isLetter(*bufferPtr)) {
    const char *end = bufferPtr + 1;

    while (charhelper::isLetter(*end))
      end++;
    llvm::StringRef word(bufferPtr, end - bufferPtr);
    token::Type type = token::KeywordFilter::getToken(word);
    if (type != token::TOK_INVALID) {
      formToken(token, end, type);
    } else {
      formToken(token, end, token::TOK_IDENTIFIER);
    }
  } else if (charhelper::isDigit(*bufferPtr)) {
    // TODO: implement floating points
    const char *end = bufferPtr + 1;
    while (charhelper::isDigit(*end))
      end++;
    formToken(token, end, token::TOK_INT_LITERAL);
  } else {
    switch (*bufferPtr) {
    case '+':
      if (peekCheck('='))
        formToken(token, bufferPtr + 2, token::OP_PLUS_ASSIGN);
      else
        formToken(token, bufferPtr + 1, token::OP_PLUS);
      break;
    case '-':
      if (peekCheck('='))
        formToken(token, bufferPtr + 2, token::OP_MINUS_ASSIGN);
      else
        formToken(token, bufferPtr + 1, token::OP_MINUS);
      break;
    case '*':
      if (peekCheck('='))
        formToken(token, bufferPtr + 2, token::OP_STAR_ASSIGN);
      else
        formToken(token, bufferPtr + 1, token::OP_STAR);
      break;
    case '/':
      if (peekCheck('='))
        formToken(token, bufferPtr + 2, token::OP_SLASH_ASSIGN);
      else
        formToken(token, bufferPtr + 1, token::OP_SLASH);
      break;
    case '=':
      if (peekCheck('='))
        formToken(token, bufferPtr + 2, token::OP_EQ);
      else
        formToken(token, bufferPtr + 1, token::OP_ASSIGN);
      break;
    case '(':
      formToken(token, bufferPtr + 1, token::PUNC_LPAREN);
      break;
    case ')':
      formToken(token, bufferPtr + 1, token::PUNC_RPAREN);
      break;
    case '{':
      formToken(token, bufferPtr + 1, token::PUNC_LBRACE);
      break;
    case '}':
      formToken(token, bufferPtr + 1, token::PUNC_RBRACE);
      break;
    case ':':
      formToken(token, bufferPtr + 1, token::PUNC_COLON);
      break;
    case ',':
      formToken(token, bufferPtr + 1, token::PUNC_COMMA);
      break;
    case ';':
      formToken(token, bufferPtr + 1, token::PUNC_SEMICOLON);
      break;
    default:
      formToken(token, bufferPtr + 1, token::TOK_INVALID);
    }
    return;
  }
}

void Lexer::formToken(token::Token &resault, const char *tokenEnd,
                      token::Type type) {
  resault.type = type;
  resault.text = llvm::StringRef(bufferPtr, tokenEnd - bufferPtr);

  bufferPtr = tokenEnd;
  return;
}
