#include <iostream>
#include <iomanip>


template<typename Type> 
void PrintMatrix(Type **& mtr, int rows, int cols, int width)
{
    for (int32_t i = 0; i < rows; ++i)
    {
        for (int32_t j = 0; j < cols; ++j)
        {
            std::cout << std::setw(width) << mtr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


template<typename Type>
void createMatrix(Type **& mtr, int rows, int cols)
{
    mtr = new Type * [rows];
    for (int32_t i = 0; i < rows; ++i)
    {
        mtr[i] = new Type [cols];
    }
}


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
    int temp_row{(n-1)/2};
    int temp_col{(n-1)/2};
    std::cout << mtr[temp_row][temp_col] << ' ';
    for (int k = 1; k <= (n - 1)/2; ++k)
    {
        --temp_row;
        std::cout << mtr[temp_row][temp_col] << ' ';
        for (int i = 0; i < 2*k - 1; ++i)
        {
            --temp_col; 
            std::cout << mtr[temp_row][temp_col] << ' ';
        }
        for (int i = 0; i < 2*k; ++i)
        {
            ++temp_row; 
            std::cout << mtr[temp_row][temp_col] << ' ';
        }
        for (int i = 0; i < 2*k; ++i)
        {
            ++temp_col; 
            std::cout << mtr[temp_row][temp_col] << ' ';
        }
        for (int i = 0; i < 2*k; ++i)
        {
            --temp_row; 
            std::cout << mtr[temp_row][temp_col] << ' ';
        }
    }
}


