#include "stringcycler.h"
char StringCycler::getNextSymbol()
{
    if(currentPosition >= inputString.length())
        return kEndOfFile;
    return inputString[currentPosition++];
}

