#include "lexer.h"
#include <iostream>
#include <cctype>

Lexer::Lexer(char* filename)
{
    std::clog << "Building lexer from source code " <<filename << "...\n";
    codePath_ = filename;
    line_ = 1;
}

Lexer::~Lexer()
{

}

std::vector<Token> Lexer::getSymbolTable()
{
    return this->symbolTable_;
}

void Lexer::run()
{
    std::clog << "Running Lexer..." << "\n";
    file_.open(codePath_);
    char c;
    
    while (file_.get(c))
    {
        
     Token tk = getToken(c);
     
     if(tk.line != -1){
      symbolTable_.push_back(tk);
     }

    }

    file_.close();
}


Token Lexer::getToken(char c){
    token_.lexeme = "";
    token_.line = -1;
    switch (c)
    {
        //COMENTARIO
        case '{':
        file_.get(c);

        if(file_.eof())
            break;

        while (c != '}')
        {

            if(c=='\n')
                line_++;

            file_.get(c);

             if(file_.eof()){
                lexerError("Comentário não fechado!");
                break;
             }
        }
        
        break;

        //SOMA | SUB
        case '+':
        case '-':
        token_.lexeme = c;
        token_.line = line_;
        token_.classification = TokenType::AddOp;
        break;

        //MULT | DIV
        case '*':
        case '/':
        token_.lexeme = c;
        token_.line = line_;
        token_.classification = TokenType::MultOp;
         
        break;

        //IGUAL
        case '=':
        token_.lexeme = c;
        token_.line = line_;
        token_.classification = TokenType::RelOp;
         
        break;

        //PONTO | PONTOEVIRGULA | VIRGULA | PARENTESES
        case '.':
        case ';':
        case ',':
        case '(':
        case ')':
        token_.lexeme = c;
        token_.line = line_;
        token_.classification = TokenType::Delimiter;
        break;

        //ATRIBUIÇÃO | DOIS PONTOS
        case ':':
        token_.lexeme = c;
        file_.get(c);
        
        //TODO: teste
        if(file_.eof())
            break;

        if(c == '=')
        {
            token_.lexeme += c;
            token_.line = line_;
            token_.classification = TokenType::AttCommand;
        } else {
            token_.line = line_;
            token_.classification = TokenType::Delimiter;
            file_.unget();
            break;
        }
         
        break;
    
        //MENORIGUAL | MENOR | DIFERENTE
        case '<':
        token_.lexeme = c;
        file_.get(c);

        if(file_.eof())
            break;

        if(c == '=' || c == '>')
        {
            token_.lexeme += c;
            token_.line = line_;
            token_.classification = TokenType::RelOp;
        } else {
            token_.line = line_;
            token_.classification = TokenType::RelOp;
            file_.unget();
            break;
        } 
        break;

        //MAIOR | MAIORIGUAL
        case '>':
        token_.lexeme = c;
        file_.get(c);

          if(file_.eof())
            break;

        if(c == '=')
        {
            token_.lexeme += c;
            token_.line = line_;
            token_.classification = TokenType::RelOp;
        } else {
            token_.line = line_;
            token_.classification = TokenType::RelOp;
            file_.unget();
            break;
        }
        break;

/*
        //DO
        case 'd':
        token_.lexeme = c;
        file_.get(c);

        if(c == 'o')
        {
            token_.lexeme+=c;
            file_get(c);

            if (!std::isalnum(c))
            {
                token_.line = line_;
                token_.classification = TokenType::ResWord;
                file_.unget();
            } else {
                token_.lexeme = readIdentifier(token_.lexeme);
                token_.line = line_;
                token_.classification = TokenType::Identifier;
            }   

        } else {
            token_.lexeme = readIdentifier(token_.lexeme);
            token_.line = line_;
            token_.classification = TokenType::Identifier;
        }
        break;

        //VAR
        case 'v':
        token_.lexeme=c;
        file_.get(c);
        
        if(c=='a')
        {
            token_.lexeme+=c;
            file_.get(c);
            
            if(c=='r')
            {
                token_.lexeme+=c;
                file_.get(c);
                
                if(!std::isalnum(c))
                {
                    token_.line = line_;
                    token_.classification = TokenType::ResWord;
                    file_.unget();
                    break;
                }

            }
        }

        file.unget();
        token_.lexeme = readIdentifier(token_.lexeme);
        token_.line = line_;
        token_.classification = TokenType::Identifier;
        break;


        //NOT
        case 'n':
        token_.lexeme=c;
        file_.get(c);
        
        if(c=='o')
        {
            token_.lexeme+=c;
            file_.get(c);
            
            if(c=='t')
            {
                token_.lexeme+=c;
                file_.get(c);
                
                if(!std::isalnum(c))
                {
                    token_.line = line_;
                    token_.classification = TokenType::ResWord;
                    file_.unget();
                    break;
                }

            }
        }

        file.unget();
        token_.lexeme = readIdentifier(token_.lexeme);
        token_.line = line_;
        token_.classification = TokenType::Identifier;
        break;
*/
        case '\n':
        line_++;         
        break;

    
    default:
        //IDENTIFIER | RESERVED WORD
        if(std::isalpha(c)){
            token_.lexeme = c;
            token_.lexeme = readIdentifier(token_.lexeme);
            token_.line = line_;

            //busca nas palavras reservadas
            if(resWords.find(token_.lexeme)==resWords.end()) //se não achou
            {
                //OR
                if(token_.lexeme == "or"){
                    token_.classification = TokenType::AddOp;
                //AND
                } else if (token_.lexeme == "and"){
                    token_.classification = TokenType::MultOp;           
                } else {
                token_.classification = TokenType::Identifier;
                }
            } else {
                token_.classification = TokenType::ResWord;
            }
        
        //REAL NUMBER | INTEGER
        } else if(std::isdigit(c)){
            token_.lexeme = c;
            token_.lexeme = readNumber(token_.lexeme); //já classifica em real ou inteiro
            token_.line = line_;
        } else if(std::isspace(c)) {
            ;//pula
        } else {
            token_.lexeme = c;
            lexerError("Símbolo não pertence à linguagem!");
        }

        break;
    }
    
    return token_;

}

std::string Lexer::readNumber(std::string currentLexeme){
    std::string lexeme = currentLexeme;
    char c;
    file_.get(c);

    while(isdigit(c)){
        lexeme+=c;
        file_.get(c);

        if(file_.eof())
            return lexeme;

    }
    
    if(c == '.'){
        lexeme+=c;
        token_.classification = TokenType::RealNumber;
    } else
    {
        token_.classification = TokenType::IntNumber;
        file_.unget();
        return lexeme;
    }

    while(isdigit(c)){
        lexeme+=c;
        file_.get(c);

         if(file_.eof())
            return lexeme;

    }


    file_.unget();
    return lexeme;
}

std::string Lexer::readIdentifier(std::string currentLexeme){
    std::string lexeme = currentLexeme;
    char c;
    file_.get(c);

    if(file_.eof())
        return lexeme;

    while(isalnum(c) || c == '_'){
        lexeme+=c;
        file_.get(c);
    
        if(file_.eof())
            return lexeme;

    }
    file_.unget();
    return lexeme;

}

void Lexer::lexerError(std::string msg){
    std::clog << "[ERRO LÉXICO]" << msg <<"\n";
    std::clog << "Linha: " << line_ << "\n";
    std::clog << "Token: " << token_.lexeme << "\n";
}