#include <iostream>
#include <cstring>
#include <exception>

int returnSumOfDigits(int number)
{
    int res{};
    while (number != 0)
    {
        res += number %10;
        number /= 10;
    }
    return res;
}


void sortNumberWords(char * str)
{
    const int n{strlen(str) + 1};
    char temp_str[2*n]{};
    char * arr[n]{};
    bool gran[n]{};
    int counter_of_number_words{};
    int posIndex{};

    if (n==1)
    {
        throw (std::invalid_argument("String must be non void"));
    }

    
    for(int i = 0; i < n - 1; ++i)
    {
        if ((str[i] <= '9' && str[i] >= '0' && str[i + 1] == ' ') || (str[i + 1] <= '9' && str[i + 1] >= '0' && str[i] == ' '))
        {
            gran[i] = true;
        }
    }
    for (int i = 0; i < 2*n; ++i)
    {      
        if (posIndex >= strlen(str))
        {
            break;
        }
        temp_str[i] = str[posIndex++];
        if (gran[posIndex - 1])
        {
            temp_str[++i] = '\0';
        }
 

    }
    posIndex = 0;
    arr[posIndex++] = temp_str;
    for (int i = 0; i < 2*n; ++i)
    {
        if (temp_str[i] == '\0')
        {
            if(temp_str[i+1] == '\0')
            {
                break;
            }
            arr[posIndex++] = temp_str + i + 1;
        }
    }
    posIndex = 0;
    int arr_of_numberic_idx[n]{};
    int count_of_indexes{};
    for (int i = 0; i < n; ++i)
    {
        if(arr[i] == nullptr)
        {
            break;
        }

        for (int j = 0; j < strlen(arr[i]); ++j)
        {
            if (arr[i][j] <'0' || arr[i][j] > '9')
            {
                break;
            }
            if (j == strlen(arr[i]) - 1)
            {
                arr_of_numberic_idx[posIndex++] = i;
                ++count_of_indexes;
            }
         }
        
    }
    posIndex = 0;
    while(posIndex < count_of_indexes - 1)
    {
        if (returnSumOfDigits(atoi(arr[arr_of_numberic_idx[posIndex]])) < returnSumOfDigits(atoi(arr[arr_of_numberic_idx[posIndex + 1]])))
        {
            std::swap(arr[arr_of_numberic_idx[posIndex]], arr[arr_of_numberic_idx[posIndex + 1]]);
            posIndex = 0;
        }
        else
        {
            ++posIndex;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i];
    } 
    
}