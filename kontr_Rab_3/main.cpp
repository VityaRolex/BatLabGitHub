#include <iostream>
#include <fstream>
#include "funcs.h"

int main()
{
    std::fstream f("input.txt", std::ios::in);
    int length{};
    Student * arr_of_studs{};
    int switcher{};
    makeStudArr(arr_of_studs, f, length);
    while(true)
    {
        std::cout << "Input 1 for Surname Sort of Array and output it in start file, 2 for search a stud with his Surname and get result to console, 3 for Group sort of Array and Surname sort of groupes and get result to console, 4 for get information about average mark in groupes and 5 for exit \n";
        inputIntegerValue(switcher);
        switch(switcher)
        {
        case 1:
        {
            SortArr(arr_of_studs, length);
            std::ofstream fout("input.txt");
            outputInFile(arr_of_studs, length, fout);
            fout.close();
            break;
        }
        case 2:
        {
            searchStud(arr_of_studs, length);
            break;
        }
        case 3:
        {
            sortByGroup(arr_of_studs, length);
            outputInFile(arr_of_studs, length, std::cout);
            break;
        }
        case 4:
        {
            Student * temp_arr{};
            copyArr(arr_of_studs, length, temp_arr);
            sortByGroup(temp_arr, length);
            AverageMarkOfGroups(temp_arr, length);
            break;
        }
        case 5:
        {
            return 0;
        }
        }
    }

    
    return 0;
}