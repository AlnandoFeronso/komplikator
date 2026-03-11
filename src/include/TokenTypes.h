#pragma once
#include <llvm/ADT/StringMap.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/SMLoc.h>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
class Lexer;

namespace token {

enum Type {
  TOK_EOF = 0, // End of file
  TOK_INVALID, // invalid tokens

  TOK_IDENTIFIER,     // variables and function names
  TOK_INT_LITERAL,    // int constant
  TOK_FLOAT_LITERAL,  // flaot constant
  TOK_CHAR_LITERAL,   // char constant
  TOK_STRING_LITERAL, // string constant

  KW_DEFAULT,
  KW_DO,
  KW_DOUBLE,
  KW_ELSE,
  KW_ENUM,
  KW_EXTERN,
  KW_FLOAT,
  KW_FOR,
  KW_GOTO,
  KW_IF,
  KW_INLINE,
  KW_INT,
  KW_LONG,
  KW_RETURN,
  KW_SHORT,
  KW_SIGNED,
  KW_SIZEOF,
  KW_STATIC,
  KW_STRUCT,
  KW_SWITCH,
  KW_TYPEDEF,
  KW_UNION,
  KW_UNSIGNED,
  KW_VOID,
  KW_VOLATILE,
  KW_WHILE,

  OP_ASSIGN, // =
  OP_PLUS,   // +
  OP_MINUS,  // -
  OP_STAR,   // *
  OP_SLASH,  // /
  OP_MOD,    // %
  OP_INC,    // ++
  OP_DEC,    // --

  OP_EQ,          // ==
  OP_NEQ,         // !=
  OP_LESS,        // <
  OP_GREATER,     // >
  OP_LESS_EQ,     // <=
  OP_GREATER_EQ,  // >=
  OP_LOGICAL_AND, // &&
  OP_LOGICAL_OR,  // ||
  OP_LOGICAL_NOT, // !

  OP_BITWISE_AND, // &
  OP_BITWISE_OR,  // |
  OP_BITWISE_XOR, // ^
  OP_BITWISE_NOT, // ~
  OP_LEFT_SHIFT,  // <<
  OP_RIGHT_SHIFT, // >>

  OP_PLUS_ASSIGN,   // +=
  OP_MINUS_ASSIGN,  // -=
  OP_STAR_ASSIGN,   // *=
  OP_SLASH_ASSIGN,  // /=
  OP_MOD_ASSIGN,    // %=
  OP_AND_ASSIGN,    // &=
  OP_OR_ASSIGN,     // |=
  OP_XOR_ASSIGN,    // ^=
  OP_LSHIFT_ASSIGN, // <<=
  OP_RSHIFT_ASSIGN, // >>=

  PUNC_LPAREN,    // (
  PUNC_RPAREN,    // )
  PUNC_LBRACE,    // {
  PUNC_RBRACE,    // }
  PUNC_LBRACKET,  // [
  PUNC_RBRACKET,  // ]
  PUNC_COMMA,     // ,
  PUNC_SEMICOLON, // ;
  PUNC_COLON,     // :
  PUNC_QUESTION,  // ?
  PUNC_DOT,       // .
  PUNC_ARROW,     // ->
  PUNC_ELLIPSIS   // ...
};

// DEFINITIONS

class KeywordFilter;
class Token;

// returns type
Type deduceDigitType();
std::string typeToString(Type type);



class KeywordFilter {
  static const llvm::StringMap<Type> tokenTable;
public:
  static Type getToken(const llvm::StringRef str) {
    auto itr = tokenTable.find(str);
    if (itr == tokenTable.end())
      return TOK_INVALID;
    return itr->second;
  }
};

class Token {
  friend Lexer;

public:
private:
  Type type;
  llvm::StringRef text;

public:
  Type getType() const { return type; }
  size_t getLength() const { return text.size(); }
  llvm::StringRef getText() const { return text; }

  llvm::SMLoc getLocation() const {
    return llvm::SMLoc::getFromPointer(text.begin());
  }

  bool is(Type t) const { return t == type; }
  bool isOneOf(Type t1, Type t2) { return (t1 == type || t2 == type); };
  template <typename... T> bool isOneOf(Type t1, Type t2, T... ts) const {
    return is(t1) || isOneOf(t2, ts...);
  }
};
} // namespace token
