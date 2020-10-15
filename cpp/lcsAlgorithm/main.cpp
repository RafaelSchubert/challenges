#include <iostream>
#include <string>
#include "lcs.h"


int main()
{
    std::string textA;
    std::string textB;
    int         n = 0;

    std::cin >> n;

    for (; n > 0; --n)
    {
        std::cin >> textA >> textB;

        std::cout << lcs(textA, textB) << '\n';
    }

    return 0;
}
