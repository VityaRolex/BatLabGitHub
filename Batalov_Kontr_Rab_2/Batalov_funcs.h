#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdexcept>

struct Word
{
    int i = 0;
    char word [256]{};
};


void makeArr(char **& arr, int  &length)
{
       std::cout << "Enter amount of Words \n";
       std::cin >> length;
       if (length <= 0)
       {
        throw std::out_of_range("Amount of Words must be positive");
       }
    arr = new char * [length];
    
    for (int i = 0; i < length; ++i)
    {
        arr[i] = new char [256];
    }
}


void sort(Word * arr,)
{
    
}

int returnMaxOfArr(int * arr, int length)
{
    int res{arr[0]};
    for (int i = 0; i < length; ++i)
    {
        if(res < arr[i])
        {
            res = arr[i];
        }
    }
    return res;
}


int returnMinOfArr(int * arr, int length)
{
    int res{arr[0]};
    for (int i = 0; i < length; ++i)
    {
        if(res > arr[i])
        {
            res = arr[i];
        }
    }
    return res;
}

int returnSumOfArr(int * arr, int length)
{
    int res{};
    for (int i = 0; i < length; ++i)
    {
        res += arr[i];
    }
    return res;
}

void Task1(char **& arr, int length)
{
    Word words[length];
    int arr_of_nums[length]{};
    std::cin.ignore();
    for (int i = 0; i < length; ++i)
    {
        std::cout << "Input Word number " << i+1 << '\n';
        std::cin.getline(arr[i], 256);
        arr_of_nums[i] = atoi(strpbrk(arr[i], " ")+1);
    }
    for (int i = 0; i < length; ++i)
    {
        words[i].i = arr_of_nums[i];
        words[i].word = arr[i];
    }
    sort(words, length);
    std::cout << '\n';
    for (int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << '\n';
    }
    
    std::cout << "Sum: " << returnSumOfArr(arr_of_nums, length) << '\n';
    std::cout << "Max: " << returnMaxOfArr(arr_of_nums, length) << '\n';
    std::cout << "Min: " << returnMinOfArr(arr_of_nums, length) << '\n';
}