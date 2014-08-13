#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H
#include <ctype.h>
#include "stringcycler.h"
#include "token.h"
namespace
{
    const char kGreaterThan= '>';
    const char kLessThan = '<';
    const char kForwardSlash = '/';
    const char kEqualSign = '=';
    const char kQuotes = "\"";
    const std::string kExpectedQuoteOrAlphanum = std::string("Expected a quote \" \" \" or an alphanumeric character.");
}

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
