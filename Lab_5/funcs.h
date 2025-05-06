#include <iostream>
#include "mylib.h"

int returnNumberOfANonNegativeCol(int ** mtr, int rows, int cols)
{
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            if (mtr[j][i] < 0)
            {
                break;
            }
            if (mtr[j][i] >= 0 && j == rows - 1)
            {
                return i;
            }
        }
    }
    throw "Mtr doesn't contain a non negative column \n";
}


void SpiralkaFromCenter(int **& mtr, int n)
{
    std::cout << mtr[n/2][n/2];
    for (int i = 0; i < (n + 1)/2; ++i)
    {
        for (int32_t j = 0; j < i; ++j)
        {
            std::cout << 
        }
    }
}