#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H
#include <ctype.h>
#include "stringcycler.h"
#include "token.h"

class LexicalAnalyzer
{
public:
    LexicalAnalyzer(std::string inputBuffer):myStringCycler(inputBuffer){}
    Token getNextToken();
private:
    StringCycler myStringCycler;
    char currentSymbol;

    /** Helper Functions **/
    void consumeSymbol();
    void addToLexeme(char symbol);
};

#endif // LEXICALANALYZER_H
