#include <iostream>
#include <iomanip>

void inputIntegerValue(int32_t & element)
{
    double cinTemp{};
    std::cin >> cinTemp;
    while (std::cin.fail() || cinTemp - static_cast<int32_t>(cinTemp) != 0)
 {
    if(cinTemp - static_cast<int32_t>(cinTemp) != 0)
    {
        std::cout << "it's very funny, and now enter INTEGER value \n";
    }
    if (std::cin.fail())
    {
    std::cout << "It's not funny, be more serious and try again \n";
    std::cin.clear();
    std::cin.ignore();
    }
    std::cin >> cinTemp;
  }
  element = cinTemp;
}


template <typename Type>
void createMatrix(Type **& mtr, int rows, int cols)
{
    mtr = new Type * [rows];
    for (int32_t i = 0; i < rows; ++i)
    {
        mtr[i] = new Type [cols];
    }
}


template <typename Type>
void nulliateMatrix(Type **& mtr, int rows, int cols)
{
    for (int32_t i = 0; i < rows; ++i)
    {
        for (int32_t j = 0; j < cols; ++j)
        {
            mtr[i][j]= 0;
        }
    }
}


template<typename Type>
void PrintArray(Type* arr, int32_t lenght)
{
    for (int32_t i = 0; i < lenght; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}


template<typename Type> 
void PrintMatrix(Type **& mtr, int rows, int cols, int width)
{
    for (int32_t i = 0; i < rows; ++i)
    {
        for (int32_t j = 0; j < cols; ++j)
        {
            std::cout << setw(width) << mtr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


template<typename Type>
void SdvigPoStolb(Type ** arr, int32_t rows, int32_t cols, bool right)
{
    for (int32_t i = 0; i < rows; ++i)
    {
        for (int32_t j = 0; j < cols; ++j)
        {
            if (right)
            {
                std::swap (arr[i][j], arr[i][cols - 1]);
            }
            else
            {
                std::swap (arr[i][0], arr[i][cols - 1 - j]);
            }
        }
    }
}


template<typename Type>
void SdvigPoStrok(Type ** arr, int32_t rows, int32_t cols, bool up)
{
    for (int32_t i = 0; i < rows; ++i)
    {
        for (int32_t j = 0; j < cols; ++j)
        { 
            if (up)
            {
                std::swap (arr[0][j], arr[rows - 1 - i][j]);
 
            }
            else 
            {
                std::swap (arr[i][j], arr[rows - 1][j]);
            }
        }
    }
}


template<typename Type>
void ReverseArray(Type* arr, int64_t size)
{
    int64_t lenght_of_for{size/2};
    Type tmp{};
    for(size_t i = 0; i < lenght_of_for; ++i)
    {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }

}