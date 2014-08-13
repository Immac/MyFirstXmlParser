#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <map>

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
    EndOfFile,
    Error
};
static std::map<TokenType,std::string> TokenTypeName
{
  {Id,"Id"},{Number,"Number"},{Equals,"Equals"},{Value,"Value"},{StartParentCloseTag,"StartParentCloseTag"},
  {StartParentOpenTag,"StartParentOpenTag"},
  {EndParentAnyTag,"EndParentAnyTag"},{StartSingleTag,"StartSingleTag"},{EndSingleTag,"EndSingleTag"},
  {EndOfFile,"EndOfFile"},{Error,"Error"}
};

struct Token
{
    Token(TokenType type,std::string lexeme):Type(type),Lexeme(lexeme){}
    TokenType Type;
    std::string Lexeme;
};

#endif // TOKEN_H
