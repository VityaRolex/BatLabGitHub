#include <iostream>
#include <string>
#include <cstring>
#include "funcs.h"


int main()
{
    std::string str;
    getline(std::cin, str);
    sortLatinWords(str);
    return 0;
}