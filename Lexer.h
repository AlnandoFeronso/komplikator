#pragma once

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/MemoryBuffer.h"

class Lexer{

};

class Token {
friend Lexer;
public:
  enum TokenType {
    invalid,
    eoi,
    ident,
    number,
    comma,
    colon,
    plus,
    minus,
    star,
    slash,
    l_paren,
    r_paren,
    KW_with
  };

  private:

};
