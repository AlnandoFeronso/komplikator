#include "../include/Lexer.h"
#include <iostream>

int main() {
  token::Token t;
  std::string kod = "int a = 333; \n if(a == 4)\n{return 3;}\nelse return 0;";

  Lexer l(kod);
  std::cout <<"kompilacja kodu: \n" << kod << std::endl << std::endl << std::endl;
  while (!t.is(token::TOK_EOF)) {
	   l.next(t) ;
	   std::cout <<token::typeToString(t.getType()) << "  " << t.getText().str()<<" \n";
  }
}
