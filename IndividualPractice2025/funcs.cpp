#include "head.h"

template<typename T>
void shakeSort(Type * arr, int length, bool (*compFunc)(Type, Type))
{
    bool flag{};
    int counter{};
    while(!flag)
    {
        flag = 1;
        counter = 0;
        while(counter < length - 1)
        {
            if(!compFunc(arr[counter],arr[counter+1]))
            {
                std::swap(arr[counter],arr[counter+1]);
                flag = false;   
            }
            ++conter;
        }
        while(counter > 1)
        {
            if(compFunc(arr[counter], arr[counter - 1]))
            {
                std::swap(arr[counter],arr[counter-1]);
                flag = false;
            }
            --counter;
        }
    }
};


template<typename T>
void combSort(Type * arr, int length, bool (*compFunc)(Type, Type))
{
    
    for (int step{length - 1}; step > 0; --step)
    {
        for (int i{}; i < length - step; ++i)
        {
            if(!compFunc(arr[i], arr[i+step]))
            {
                std::swap(arr[i], arr[i + step]);
            }
        }
    }
};


template<typename T>
void countSort(Type * arr, int length, int left_lim, int right_lim)
{
    int count_length{right_lim - left_lim + 1}
    int count_arr[count_length]{};
    int independent_counter{};
    for (int i{}; i < length; ++i)
    {
        ++count_arr[arr[i] - left_lim];
    }
    for(int i{}; i < count_length; ++i)
    {
        while(count_arr[i] != 0)
        {
            arr[independent_counter] = count_arr[i] + left_lim;
            --count_arr[i];
            ++independent_counter;
        }
    }
};


