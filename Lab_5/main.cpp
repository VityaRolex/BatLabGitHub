#include <iostream>
#include <iomanip>
#include "funcs.h"

int main()
{
    double ** mtr2{};
    int n = 5;
    int ** mtr = nullptr;
    createMatrix(mtr, n, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            mtr[i][j] = rand() % n - 3;
        }
    }
    PrintMatrix(mtr, n, n, 4);
    std::cout << '\n';
    mtr2 = AverageMatrix(mtr, n);
    PrintMatrix(mtr2, n, n, 5);
    catchMaxNegElem(mtr2, n);
    return 0;
}