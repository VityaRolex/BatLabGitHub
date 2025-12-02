#include <iostream>
#include "functions.h"


int main()
{
    double arr1[]{1,1,2};
    int32_t lenght1{sizeof(arr1)/sizeof(arr1[0])};
    double arr2[]{1,-2};
    int32_t lenght2{sizeof(arr2)/sizeof(arr2[0])};
    double* arr3 = new double[lenght1 + lenght2]{};
    multiplicateMnogochlens(arr1, lenght1, arr2, lenght2, arr3);
    printMnog(arr3, lenght1 + lenght2 - 2);
    std::cout << '\n';
    outputGornerScheme(arr3, lenght1 + lenght2 - 1);
}