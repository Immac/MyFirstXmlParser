#include "lexicalanalyzer.h"
Token LexicalAnalyzer::getNextToken()
{
    unsigned int currentState(0);
    std::string lexeme("");
    while(true)
    {
        switch (currentState) {
        case 0:
            if(std::isspace(currentSymbol)&&currentSymbol != kEndOfFile)
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
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 3;
            }
            else if(currentSymbol == kEqualSign)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 5;
            }
            else if(currentSymbol == kGreaterThan)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 6;
            }
            else if(currentSymbol == kLessThan)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 7;
            }
            else if(currentSymbol == kForwardSlash)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 10;
            }
            else if(currentSymbol == kEndOfFile)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 12;
            }
            else
                return Token{Error,kExpectedKnownSymbol};
            break;
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
            if(std::isalnum(currentSymbol) || std::isspace(currentSymbol))
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 3;
            }
            else if(currentSymbol == kQuotes)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 4;
            }
            else
                return Token{Error,kExpectedQuoteOrAlphanum};
            break;

        case 4:
            return Token{Value,lexeme};
        case 5:
            return Token{Equals,lexeme};
        case 6:
            return Token{EndParentAnyTag,lexeme};
        case 7:
            if (currentSymbol == kForwardSlash)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 8;
            }
            else
                currentState = 9;
            break;
        case 8:
            return Token{StartParentCloseTag,lexeme};
        case 9:
            return Token{StartParentOpenTag,lexeme};
        case 10:
            if(currentSymbol == kGreaterThan)
            {
                lexeme += currentSymbol;
                consumeSymbol();
                currentState = 11;
            }
            else
                return Token{Error,kExpectedGreaterThan};
            break;
        case 11:
            return Token{EndSingleTag,lexeme};
        case 12:
            return Token{EndOfFile,"$"};
        default:
            return Token{Error,kUnexpectedError};
            break;
        }
    }
}


void LexicalAnalyzer::consumeSymbol()
{
    currentSymbol = myStringCycler.getNextSymbol();
}
