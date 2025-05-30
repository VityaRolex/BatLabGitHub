#include <iostream>
#include <cstring>
#include "funcs.h"

int main()
{
    try
    {
    const int n{255};
    char str[n]{};
    std::cin.getline(str, n);
    sortNumberWords(str);
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
    return 0;
}