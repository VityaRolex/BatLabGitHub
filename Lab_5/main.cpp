#include <iostream>
#include <iomanip>
#include "funcs.h"

int main()
{
    int n = 5;
    int ** mtr = nullptr;
    createMatrix(mtr, n, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            mtr[i][j] = rand() % n;
        }
    }
    PrintMatrix(mtr, n, n, 4);
    SpiralkaFromCenter(mtr, n);
    
    return 0;
}