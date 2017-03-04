#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>


enum class TokenType{
    ResWord,
    Identifier,
    IntNumber,
    RealNumber,
    Delimiter,
    AttCommand,
    RelOp,
    AddOp,
    MultOp
};


struct Token{
    std::string lexeme;
    TokenType classification;
    int line;
};


static std::unordered_map<std::string, int> resWords = {
    {"var", 0},
    {"do",1},
    {"not",2},
    {"program",3},
    {"begin",4},
    {"end",5},
    {"else",6},
    {"integer",7},
    {"real",8},
    {"boolean",9},
    {"procedure",10},
    {"if",11},
    {"then",12},
    {"while",13}};

class Lexer
{
public:
    Lexer(char* filename);
    ~Lexer();
    void run();
    std::vector<Token> getSymbolTable();
    Token getToken(char c);
    void lexerError(std::string msg);
    std::string readIdentifier(std::string currentLexeme);
    std::string readNumber(std::string currentLexeme);

private:    
    std::vector<Token> symbolTable_;
    Token token_;
    int line_;
    char* codePath_;
    std::ifstream file_;
};



static std::string printType(TokenType classification)
{
    switch (classification)
    {
        case TokenType::ResWord:
            return "Palavra Reservada";

        case TokenType::Identifier:
            return "Identificador";

        case TokenType::IntNumber:
            return "Número Inteiro";

        case TokenType::RealNumber:
            return "Número Real";

        case TokenType::AddOp:
            return "Operador de Adição";

        case TokenType::AttCommand:
            return "Comando de Atribuição";

        case TokenType::Delimiter:
            return "Delimitador";

        case TokenType::RelOp:
            return "Operador Relacional";

        case TokenType::MultOp:
            return "Operador de Multiplicação";

        default:
            return " [erro] Tipo não identificado!";
            break;
    }
}

#endif