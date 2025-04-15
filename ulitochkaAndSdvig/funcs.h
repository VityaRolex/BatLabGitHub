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


template<typename Type>
void makeMatrix(Type **& arr, int32_t rows, int32_t cols)
{
    arr = new Type * [rows];
    for (int32_t i = 0; i < rows; ++i)
    {
        arr[i] = new Type [cols];
    }
}


template<typename Type>
void fillMatrix(Type ** arr, int32_t rows, int32_t cols)
{
    for (int32_t i = 0; i < rows; ++i)
    {
        for (int32_t j = 0; j < cols; ++j)
        {
            arr[i][j] = rand() % 100;
        }
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
void returnMatrix(Type **& arr, int32_t rows, int32_t cols)
{
    for (int32_t i = 0; i < rows; ++i)
    {
        for (int32_t j = 0; j < cols; ++j)
        {
            std::cout << std::setw(3) << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

template<typename Type>
void makeCycleMovement (Type ** arr, int32_t rows, int32_t cols)
{
    int32_t switcher1{-1};
    int32_t switcher2{-1};
    int32_t count{};
    std::cout << "Enter 1 if you want to move matrix horizontal or 0 for move him vertical \n";
    while (switcher1 != 0 && switcher1 != 1)
    {
        inputIntegerValue(switcher1);
    }
    std::cout << "Enter count of moves \n";
    while (count <= 0)
    {
        inputIntegerValue(count);
    }
    switch (switcher1)
    {
    case 1:
    {
        std::cout << "Enter 1 if you want to move mtr right or 0 for left \n";
        while (switcher2 != 0 && switcher2 != 1)
        {
           inputIntegerValue(switcher2);
        }
        for (int32_t i = 0; i < count; ++i)
        {
            SdvigPoStolb(arr, rows, cols, switcher2);
        }
        break;
    } 
    case 0:
    {
        std::cout << "Enter 1 if you want to move mtr up or 0 for down \n";
        while (switcher2 != 0 && switcher2 != 1)
        {
           inputIntegerValue(switcher2);
        }
        for (int32_t i = 0; i < count; ++i)
        {
            SdvigPoStrok(arr, rows, cols, switcher2);
        }
        break; 
    }
    default:
        break;
    }

}
