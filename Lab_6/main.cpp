#include <iostream>
#include <cstring>
#include "funcs2.h"

int main()
{
    const int n{255};
    char str[n]{};
    std::cin.getline(str, n);
    sortNumberWords(str);
    return 0;
}