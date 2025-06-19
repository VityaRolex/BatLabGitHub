#include <iostream>
#include <fstream>
#include <cstdlib>
#include "funcs.h"


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    bool (*func_of_comp)(double, double){};
    double * arr{};
    int length{};
    int switcher{};


    std::cout << "Input 1 if you want to input numbers from the command line and 2 if you want to input numbers from file \n"; 
    inputIntWithLimits(switcher, 1, 2);
    switch (switcher)
    {
    case 1:
        {
            CLInput(arr, length);
            break;
        }
    case 2:
        {
            fileInput(fin, arr, length);
            break;
        }
    }

    std::cout << "input 1 if you want to do increasing sort and 2 for decreasing sort \n";
    switcher = 0;
    inputIntWithLimits(switcher, 1, 2);
    switch (switcher)
    {
        case 1:
        {
            func_of_comp = func_of_increase;
            break;
        }
        case 2:
        {
            func_of_comp = func_of_decrease;
            break;
        }
    }

    std::cout << "input 1 for merge sort, 2 for insert sort, 3 for selection sort, 4 for qsort with count of digits in fractional part, 5 for Quick Sort, 6 for Modified Bubble sort \n";
    switcher = 0;
    inputIntWithLimits(switcher, 1, 6);
    switch(switcher)
    {
        case 1:
        {
            MergeSort(arr, length, func_of_comp);
            break;
        }
        case 2:
        {
            insertSort(arr, length, func_of_comp);
            break;
        }
        case 3:
        {
            selectionSort(arr, length, func_of_comp);
            break;
        }
        case 4:
        {
            Qsort(arr, length);
            break;
        }
        case 5:
        {
            QuickSort(arr, length, func_of_comp);
            break;
        }
        case 6:
        {
            ModBubbleSort(arr, length, func_of_comp);
        }
    }

    std::cout << "input 1 for output result if file, 2 for output it in command line \n";
    switcher = 0;
    inputIntWithLimits(switcher, 1, 2);
    switch (switcher)
    {
        case 1:
        {
            output(fout, arr, length);
            break;
        }
        case 2:
        {
            output(std::cout, arr, length);
        }
    }
    return 0;
}