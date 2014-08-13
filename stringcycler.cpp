#include "stringcycler.h"



char StringCycler::getNextSymbol()
{
    if(currentPosition >= inputString.length())
        return eof;
    return inputString[currentPosition++];
}

