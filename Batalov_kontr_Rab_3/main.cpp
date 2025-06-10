#include <iostream>
#include <fstream>
#include "funcs.h"

int main()
{
    std::fstream f("input.txt", std::ios::in);
    int length{};
    Student * arr_of_studs{};
    makeStudArr(arr_of_studs, f, length);
    sortByGroup(arr_of_studs, length);
    std::ofstream fout("input.txt" , std::ios::app);
    outputInFile(arr_of_studs, length, fout);
    return 0;
}