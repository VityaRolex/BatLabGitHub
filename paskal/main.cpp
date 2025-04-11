#include "funcs.h"
#include <iostream>
#include <iomanip>

int main()
{
    int32_t lenght{};
    std::cin >> lenght;
    std::cout << '\n';
    outputPascalTriangle(lenght);
    return 0;
}