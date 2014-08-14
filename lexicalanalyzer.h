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
    const char kQuotes = '\"';
    const std::string kExpectedQuoteOrAlphanum = std::string("Expected a quote \" \" \" or an alphanumeric character.");
    const std::string kExpectedGreaterThan = std::string("Expected \" > \" symbol.");
    const std::string kExpectedKnownSymbol = std::string("This Symbol is not part of this Dictionary.");
    const std::string kUnexpectedError = std::string("Something went wrong, terribly wrong!.");
}

class LexicalAnalyzer
{
public:
    LexicalAnalyzer(std::string inputBuffer):myStringCycler(inputBuffer)
    {currentSymbol = myStringCycler.getNextSymbol();}
    Token getNextToken();
private:
    StringCycler myStringCycler;
    char currentSymbol;

    /** Helper Functions **/
    void consumeSymbol();
};


#endif // LEXICALANALYZER_H
