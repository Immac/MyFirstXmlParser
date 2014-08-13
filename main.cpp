#include <iostream>
#include "lexicalanalyzer.h"

namespace
{
    const std::string kTest1 = std::string("<Vehicle><Car Type = \"PickUp\"></Vehicle>");
}


int main()
{
    LexicalAnalyzer myLA(kTest1);
    auto nextToken = myLA.getNextToken();
    while(true)
    {
        std::cout << nextToken.Lexeme << " ";
        std::cout << TokenTypeName[nextToken.Type] << "\n";
        if(nextToken.Type == Error || nextToken.Type == EndOfFile)
            break;
        nextToken = myLA.getNextToken();

    }
    system("pause");
            return 0;
}

