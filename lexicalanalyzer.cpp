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
            else if (currentSymbol == kQuotes)
            {
                consumeSymbol();
                currentState = 3;
            }
            else if(currentSymbol == kEqualSign)
            {
                consumeSymbol();
                currentState = 5;
            }
        case 1:
            if(std::isalnum(currentSymbol))
            {
                consumeSymbol();
                currentState = 1;
            }
            else
                currentState = 2;
            break;
        case 2:
            return Token(Id,lexeme);
        case 3:
            if(std::isalnum(currentSymbol) || std::isblank(currentSymbol))
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 3;
            }
            else if(currentSymbol == kQuotes)
            {
                   currentState = 4;
            }
            else
            {
                throw kExpectedQuoteOrAlphanum;
            }
            break;

        case 4:
            return Token{Value,lexeme};
        case 5:
            return Token{Equals,lexeme};
        case 6:
            if (currentSymbol == kForwardSlash)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 6;
            }
            else
                currentState = 7;
        case 6:
            return Token{StartParentCloseTag,lexeme};
        case 7:
            return Token{StartParentOpenTag,lexeme};



        default:
            break;
        }
    }
}

void LexicalAnalyzer::consumeSymbol()
{
    currentSymbol = myStringCycler.getNextSymbol();
}

