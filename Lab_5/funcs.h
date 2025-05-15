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


double** AverageMatrix(int ** mtr, int n)
{
    double** res_mtr{};
    int counter_of_neighbors{8};
    int flag{};
    createMatrix(res_mtr, n, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 || i == n - 1)
            {
                ++flag;
            }
            if (j == 0 || j == n - 1)
            {
                ++flag;
            }
            if (flag == 1)
            {
                counter_of_neighbors -= 3;
            }
            else if (flag == 2)
            {
                counter_of_neighbors -= 5;
            }
            res_mtr[i][j] = 1.0*(((j > 0 && i > 0) ? mtr[i-1][j-1] : 0) + ((i > 0) ? mtr[i-1][j] : 0) + ((i > 0 && j < n - 1) ? mtr[i-1][j+1] : 0) + ((j > 0) ? mtr[i][j-1] : 0) + ((j < n - 1) ? mtr[i][j+1] : 0) + ((i < n - 1 && j > 0) ? mtr[i+1][j-1] : 0) + ((i < n - 1)? mtr[i+1][j] : 0) + ((i < n - 1 && j < n - 1) ? mtr[i+1][j+1] : 0)) / counter_of_neighbors;
            counter_of_neighbors = 8;
            flag = 0;
        }
    }
    return res_mtr;
}


void catchMaxNegElem(double ** mtr, int n)
{
    int row{-1};
    int col{};
    double value{0};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mtr[i][j] < 0)
            {
                if ( row == -1)
                {
                    value = mtr[i][j];
                    row = i;
                    col = j;
                }
                else if(mtr[i][j] > value)
                {
                    value = mtr[i][j];
                    row = i;
                    col = j;
                }
            }
            
        }
    }
    if (row == -1)
    {
        throw "mtr doesn't contain negative elements";
    }
    std::cout << "Max negative element is " << value << " and it is in the " << row+1 << " row and the " << col+1 << " column \n";
}