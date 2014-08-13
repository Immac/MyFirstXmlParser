#include <iostream>
#include "stringcycler.h"

namespace
{
    const std::string kTest1 = std::string("Hello World");
}


int main()
{
    StringCycler myStringCycler(kTest1);
    auto currentChar = myStringCycler.getNextSymbol();
    while(currentChar != kEndOfFile)
    {
        std::cout << currentChar;
        currentChar = myStringCycler.getNextSymbol();
    }
    return 0;
}

