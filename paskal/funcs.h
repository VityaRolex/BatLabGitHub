#include <iostream>
#include <iomanip>


void printArray(u_int64_t * arr, int32_t lenght)
{
    for (int32_t i = 0; i < lenght; ++i)
    {
        std::cout << std::setw(4) << arr[i] << ' ';
    }
    std::cout << '\n';
}


void outputPascalTriangle(int32_t number_of_string)
{
    int counter{1};
    u_int64_t * concrete_string = new u_int64_t [1];
    concrete_string[0] = 1;
    printArray(concrete_string, 1);
    u_int64_t * next_string = new u_int64_t [2];
    while (counter != number_of_string)
    {
        for (int32_t i = 0; i < counter + 1; ++i)
        {
            next_string[i] = 1;
        }
        for (int32_t i = 1; i < counter; ++i)
        {
            next_string[i] = concrete_string[i-1] + concrete_string[i];
        }
        printArray(next_string, counter + 1);
        delete [] concrete_string;
        concrete_string = new u_int64_t[counter + 1];
        for (int32_t i = 0; i < counter + 1; ++i)
        {
            concrete_string[i] = next_string[i];
        }
        delete [] next_string;
        next_string = new u_int64_t [counter + 2];
        counter += 1;
    }
}