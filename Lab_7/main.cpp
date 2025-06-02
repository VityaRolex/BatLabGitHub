#include <iostream>
#include <string>
#include <cstring>
#include "funcs.h"


int main()
{
    std::string str;
    getline(std::cin, str);
    char string[255]{};
    sortLatinWords(str);
    return 0;
}