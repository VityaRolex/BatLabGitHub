#include <iostream>
#include <cstring>
#include "tasks.h"

int main()
{
    char string[100]{};
    char divides[] = ".,()\t ";

    EnterString(string, 100);
    Task5(string, divides);
    return 0;
}