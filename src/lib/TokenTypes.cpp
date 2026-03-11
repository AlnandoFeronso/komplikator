#include "../include/TokenTypes.h"

using namespace token;
std::string token::typeToString(Type type) {
  switch (type) {
  case TOK_EOF:
    return "TOK_EOF";
  case TOK_INVALID:
    return "TOK_INVALID";

  case TOK_IDENTIFIER:
    return "TOK_IDENTIFIER";
  case TOK_INT_LITERAL:
    return "TOK_INT_LITERAL";
  case TOK_FLOAT_LITERAL:
    return "TOK_FLOAT_LITERAL";
  case TOK_CHAR_LITERAL:
    return "TOK_CHAR_LITERAL";
  case TOK_STRING_LITERAL:
    return "TOK_STRING_LITERAL";

  case KW_DEFAULT:
    return "KW_DEFAULT";
  case KW_DO:
    return "KW_DO";
  case KW_DOUBLE:
    return "KW_DOUBLE";
  case KW_ELSE:
    return "KW_ELSE";
  case KW_ENUM:
    return "KW_ENUM";
  case KW_EXTERN:
    return "KW_EXTERN";
  case KW_FLOAT:
    return "KW_FLOAT";
  case KW_FOR:
    return "KW_FOR";
  case KW_GOTO:
    return "KW_GOTO";
  case KW_IF:
    return "KW_IF";
  case KW_INLINE:
    return "KW_INLINE";
  case KW_INT:
    return "KW_INT";
  case KW_LONG:
    return "KW_LONG";
  case KW_RETURN:
    return "KW_RETURN";
  case KW_SHORT:
    return "KW_SHORT";
  case KW_SIGNED:
    return "KW_SIGNED";
  case KW_SIZEOF:
    return "KW_SIZEOF";
  case KW_STATIC:
    return "KW_STATIC";
  case KW_STRUCT:
    return "KW_STRUCT";
  case KW_SWITCH:
    return "KW_SWITCH";
  case KW_TYPEDEF:
    return "KW_TYPEDEF";
  case KW_UNION:
    return "KW_UNION";
  case KW_UNSIGNED:
    return "KW_UNSIGNED";
  case KW_VOID:
    return "KW_VOID";
  case KW_VOLATILE:
    return "KW_VOLATILE";
  case KW_WHILE:
    return "KW_WHILE";

  case OP_ASSIGN:
    return "OP_ASSIGN";
  case OP_PLUS:
    return "OP_PLUS";
  case OP_MINUS:
    return "OP_MINUS";
  case OP_STAR:
    return "OP_STAR";
  case OP_SLASH:
    return "OP_SLASH";
  case OP_MOD:
    return "OP_MOD";
  case OP_INC:
    return "OP_INC";
  case OP_DEC:
    return "OP_DEC";

  case OP_EQ:
    return "OP_EQ";
  case OP_NEQ:
    return "OP_NEQ";
  case OP_LESS:
    return "OP_LESS";
  case OP_GREATER:
    return "OP_GREATER";
  case OP_LESS_EQ:
    return "OP_LESS_EQ";
  case OP_GREATER_EQ:
    return "OP_GREATER_EQ";
  case OP_LOGICAL_AND:
    return "OP_LOGICAL_AND";
  case OP_LOGICAL_OR:
    return "OP_LOGICAL_OR";
  case OP_LOGICAL_NOT:
    return "OP_LOGICAL_NOT";

  case OP_BITWISE_AND:
    return "OP_BITWISE_AND";
  case OP_BITWISE_OR:
    return "OP_BITWISE_OR";
  case OP_BITWISE_XOR:
    return "OP_BITWISE_XOR";
  case OP_BITWISE_NOT:
    return "OP_BITWISE_NOT";
  case OP_LEFT_SHIFT:
    return "OP_LEFT_SHIFT";
  case OP_RIGHT_SHIFT:
    return "OP_RIGHT_SHIFT";

  case OP_PLUS_ASSIGN:
    return "OP_PLUS_ASSIGN";
  case OP_MINUS_ASSIGN:
    return "OP_MINUS_ASSIGN";
  case OP_STAR_ASSIGN:
    return "OP_STAR_ASSIGN";
  case OP_SLASH_ASSIGN:
    return "OP_SLASH_ASSIGN";
  case OP_MOD_ASSIGN:
    return "OP_MOD_ASSIGN";
  case OP_AND_ASSIGN:
    return "OP_AND_ASSIGN";
  case OP_OR_ASSIGN:
    return "OP_OR_ASSIGN";
  case OP_XOR_ASSIGN:
    return "OP_XOR_ASSIGN";
  case OP_LSHIFT_ASSIGN:
    return "OP_LSHIFT_ASSIGN";
  case OP_RSHIFT_ASSIGN:
    return "OP_RSHIFT_ASSIGN";

  case PUNC_LPAREN:
    return "PUNC_LPAREN";
  case PUNC_RPAREN:
    return "PUNC_RPAREN";
  case PUNC_LBRACE:
    return "PUNC_LBRACE";
  case PUNC_RBRACE:
    return "PUNC_RBRACE";
  case PUNC_LBRACKET:
    return "PUNC_LBRACKET";
  case PUNC_RBRACKET:
    return "PUNC_RBRACKET";
  case PUNC_COMMA:
    return "PUNC_COMMA";
  case PUNC_SEMICOLON:
    return "PUNC_SEMICOLON";
  case PUNC_COLON:
    return "PUNC_COLON";
  case PUNC_QUESTION:
    return "PUNC_QUESTION";
  case PUNC_DOT:
    return "PUNC_DOT";
  case PUNC_ARROW:
    return "PUNC_ARROW";
  case PUNC_ELLIPSIS:
    return "PUNC_ELLIPSIS";

  default:
    return "UNKNOWN_TYPE";
  }
}

const llvm::StringMap<Type> KeywordFilter::tokenTable = {
    {"default", KW_DEFAULT}, {"do", KW_DO},
    {"double", KW_DOUBLE},   {"else", KW_ELSE},
    {"enum", KW_ENUM},       {"extern", KW_EXTERN},
    {"float", KW_FLOAT},     {"for", KW_FOR},
    {"goto", KW_GOTO},       {"if", KW_IF},
    {"inline", KW_INLINE},   {"int", KW_INT},
    {"long", KW_LONG},       {"return", KW_RETURN},
    {"short", KW_SHORT},     {"sizeof", KW_SIZEOF},
    {"static", KW_STATIC},   {"struct", KW_STRUCT},
    {"switch", KW_SWITCH},   {"typedef", KW_TYPEDEF},
    {"union", KW_UNION},     {"unsigned", KW_UNSIGNED},
    {"void", KW_VOID},       {"volatile", KW_VOLATILE},
    {"while", KW_WHILE},
};
