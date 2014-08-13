#include "lexicalanalyzer.h"
Token LexicalAnalyzer::getNextToken()
{
    currentSymbol = myStringCycler.getNextSymbol();
    unsigned int currentState(0);
    std::string lexeme("");
    while(true)
    {
        switch (currentState) {
        case 0:
            if(std::isspace(currentSymbol))
            {
                consumeSymbol();
                currentState = 0;
            }
            else if (std::isalpha(currentSymbol))
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 1;
            }
            else if (std::isdigit(currentSymbol))
            {
                consumeSymbol();
                currentState = 3;
            }
        case 1:
            if(std::isalnum(currentSymbol))
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 1;
            }
            else
                currentState = 2;
            break;
        case 2:
            return Token(Id,lexeme);
        case 3:
            if(std::isdigit(currentSymbol))
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 3;
            }
            else
                currentState = 6;

        default:
            break;
        }
    }
}

void LexicalAnalyzer::consumeSymbol()
{
    currentSymbol = myStringCycler.getNextSymbol();
}

