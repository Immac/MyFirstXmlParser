#ifndef STRINGCYCLER_H
#define STRINGCYCLER_H
#include <iostream>
namespace
{
    const char kEndOfFile = '\n';
}
class StringCycler
{
public:
    StringCycler(std::string inputString):inputString(inputString),currentPosition(0){}
    char getNextSymbol();
private:
    std::string inputString;
    size_t currentPosition;
    char currentSymbol;
};

#endif // STRINGCYCLER_H
