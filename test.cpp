#include<iostream>
#include"mylib.h"
#include <string>

int main()
{
    const size_t SIZE = 5;
    std::string  arr[SIZE]{};
    std::cin >> arr[0] >> arr[1];
    ArrWithLength temp = makeArrWithLengthFromArr(arr, SIZE);
    std::cout  << temp;
    return 0;
}