#include <iostream>


char returnSign(double number)
{
    return number >= 0 ? '+' : '-';
}


void reverseArray(double * arr, int32_t lenght)
{
    double temp{};
    for (int32_t i = 0; i <= (lenght-1)/2; ++i)
    {
        temp = arr[i];
        arr[i] = arr[lenght - i - 1];
        arr[lenght - i - 1] = temp;
    }
}


void printArray(double * arr, int32_t lenght)
{
    for (int32_t i = 0; i < lenght; ++i)
    {
        std::cout << arr[i] << ' ';
    }
}


void multiplicateMnogochlens(double * mnog1, int32_t lenght1, double * mnog2, int32_t lenght2, double * mnog3)
{
    reverseArray(mnog1, lenght1);
    reverseArray(mnog2, lenght2);
    for (int32_t i = 0; i < lenght1; ++i)
    {
        for (int32_t j = 0; j < lenght2; ++j)
        {
            mnog3[i+j] += mnog1[i] * mnog2[j];
        }
    }
    reverseArray(mnog3,lenght1 + lenght2-1);
}


void printMnog(double * mnog, int32_t power)
{
    const int32_t lenght_of_mnog{power + 1};
    for (int32_t i = 0; i < lenght_of_mnog; ++i)
    {
        if (mnog[i] != 0)
        {   
            if (i == 0 && mnog[i] != 1 && mnog[i] != -1)
            {
                std::cout << mnog[i];
            }
            else if (i == 0 && mnog[i] == 1)
            {
                
            }
            else
            {
                std::cout << returnSign(mnog[i]);
                if (mnog[i] != 1 && mnog[i] != -1)
                {
                    std::cout << ' ' << abs(mnog[i]); 
                }
            }
            if (power != 1 && power != 0)
            {
                std::cout << "x^" << power << ' ';
            }
            else if (power == 1)
            {
                std::cout << "x ";
            }
            else if (power == 0)
            {

            }
        }
        power -= 1;
    }
}


void outputGornerScheme(double * arr,int32_t lenght)
{
    for (int32_t i = 0; i < lenght - 2; ++i)
    {
        std::cout << '(';
    }
    if (arr[0] == -1)
    {
        std::cout << '-';
    }
    else if (arr[0] == 1)
    {
        
    }
    else 
    {
        std::cout << arr[0];
    }
    std::cout << "x ";
    for (int32_t i = 1; i < lenght; ++i)
    {
        std::cout << returnSign(arr[i]) << ' ' << abs(arr[i]);
        if(i != lenght - 1) 
        {
            std::cout << ")x ";
        }
    }
}