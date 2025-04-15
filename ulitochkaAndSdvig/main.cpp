#include <iostream>
#include "funcs.h"
int main()
{
    int32_t ** arr{nullptr};
    int32_t cols{10};
    int32_t rows{10};
    makeMatrix(arr, rows, cols);
    fillMatrix(arr,rows, cols);
    returnMatrix(arr, rows, cols);
    std::cout << '\n';
    makeCycleMovement(arr, rows, cols);
    returnMatrix(arr,rows, cols);
    std::cout << '\n';
}