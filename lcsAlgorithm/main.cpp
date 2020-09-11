#include <iostream>
#include <string>
#include "lcs.h"


int main()
{
    std::string textA;
    std::string textB;

    std::cin >> textA >> textB;

    std::cout << lcs(textA, textB);

    return 0;
}
