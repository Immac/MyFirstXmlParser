#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

enum TokenType
{
    Id,
    Number,
    Equals,
    Value,
    StartParentCloseTag,
    StartParentOpenTag,
    EndParentAnyTag,
    StartSingleTag,
    EndSingleTag,
    EndOfFile
};

struct Token
{
    Token(TokenType type,std::string lexeme):Type(type),Lexeme(lexeme){}
    TokenType Type;
    std::string Lexeme;
};

#endif // TOKEN_H
