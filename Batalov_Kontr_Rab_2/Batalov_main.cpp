#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include "Batalov_funcs.h"

int main()
{
    int length{};
    char ** wordarray = nullptr;
    try
    {
    makeArr(wordarray, length);
    Task1(wordarray, length);
    }
    catch(std::out_of_range & e)
    {
        std::cout << e.what();
    }
    return 0;
}
