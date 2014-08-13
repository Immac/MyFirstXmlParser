#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

enum TokenType
{
    Addition,
    Substraction,
    Multiplication,
    Division,
    LeftParenthesis,
    RightParenthesis,
    Id,
    Number,
    EndOfFile,
    Equals
};

struct Token
{
    Token(TokenType type,std::string lexeme):Type(type),Lexeme(lexeme){}
    TokenType Type;
    std::string Lexeme;
};

#endif // TOKEN_H
