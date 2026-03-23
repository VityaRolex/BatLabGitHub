#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdexcept>

struct DoubleNumber
{
    int i = 0;
    int val = 0;
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


int compareElems(const void * elem1, const void * elem2)
{
    return ((*((DoubleNumber*)elem1)).val) - ((*((DoubleNumber*)elem2)).val);
}


void sort(DoubleNumber * arr, int length)
{
    qsort(arr,length, sizeof(DoubleNumber), compareElems);
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
    DoubleNumber numbers[length];
    int arr_of_nums[length]{};
    std::cin.ignore();
    for (int i = 0; i < length; ++i)
    {
        std::cout << "Input Word number " << i+1 << '\n';
        std::cin.getline(arr[i], 256);
        arr_of_nums[i] = atoi(strpbrk(arr[i], " ")+1);
        numbers[i].i = i;
        numbers[i].val = arr_of_nums[i];
    }
    

    sort(numbers, length);


    std::cout << '\n';
    for (int i = 0; i < length; ++i)
    {
        std::cout <<  arr[numbers[i].i] << '\n';
    }
    
    std::cout << "Sum: " << returnSumOfArr(arr_of_nums, length) << '\n';
    std::cout << "Max: " << returnMaxOfArr(arr_of_nums, length) << '\n';
    std::cout << "Min: " << returnMinOfArr(arr_of_nums, length) << '\n';
}