#include "lexer.h"
#include <iostream>

int main(int argc, char** argv){

    Lexer analisadorlexico(argv[1]);
    
    analisadorlexico.run();

    for(Token tok : analisadorlexico.getSymbolTable())
    {
        std::cout << tok.lexeme << "\t"<<printType(tok.classification) << "\t" << tok.line << std::endl;
    }


    return 0;
}