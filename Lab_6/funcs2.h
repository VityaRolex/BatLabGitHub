#include <iostream>
#include <cstring>
#include <exception>


int returnSumOfDigits(int number)
{
    int res{};
    number = std::abs(number);
    while (number != 0)
    {
        res += number %10;
        number /= 10;
    }
    return res;
}


bool isNumber(char * word, int length)
{
    
    for(int i = 0; i < length; ++i)
    {
        if(!isdigit(word[i]) && !(i == 0 && word[i] == '-'))
        {
            return false;
        }
    }
    return true;
}


void makeAnWordArr(char **& words, char * str, int& counter_of_words, int& counter_of_number_words)
{
    int k{};
    int length_of_str = strlen(str);
    words = new char * [length_of_str];
    for (int j = 0; j < length_of_str; ++j)
    {
        for (int i = j; i < length_of_str; ++i)
        {
            if (((str[i] != ' ' && str[i+1] == ' ') || (str[i] == ' ' && str[i+1] != ' ')) || i == length_of_str - 1)
            {
                words[k] = new char [i - j + 2];
                strncpy(words[k], str + j, i - j + 1);
                strcat(words[k],"");
                if(isNumber(words[k], strlen(words[k])))
                {
                    ++counter_of_number_words;
                }
                ++k;
                ++counter_of_words;
                j = i;
                i = length_of_str;
            }
        }
    }
}


void makeArrOfNumIdx(int *& arr_of_idx, int count_of_num_words, char **& words, int count_of_words)
{
    int k{};
    arr_of_idx = new int [count_of_num_words];
    for (int i = 0; i < count_of_words; ++i)
    {
        if (isNumber(words[i], strlen(words[i])))
        {
            arr_of_idx[k] = i;
            ++k;
        }
    }
}

template<typename Type>
void sortElementsWithIdxArr(Type * arr, int * idx_arr, int idx_arr_length)
{
    int k{};
    while (k != idx_arr_length - 1)
    {
        if (returnSumOfDigits(atoi(arr[idx_arr[k]])) < returnSumOfDigits(atoi(arr[idx_arr[k + 1]])))
        {
            std::swap(arr[idx_arr[k]], arr[idx_arr[k+1]]);
            k = 0;
        }
        else
        {
            ++k;
        }
    }
}


void sortNumberWords(char* str)
{
    int counter_of_number_words{};
    int counter_of_words{};
    int length_of_str = strlen(str);
    char ** words{};
    int * arr_of_num_idx{};
    makeAnWordArr(words, str, counter_of_words,counter_of_number_words);
    makeArrOfNumIdx(arr_of_num_idx, counter_of_number_words, words, counter_of_words);
    sortElementsWithIdxArr(words, arr_of_num_idx, counter_of_number_words);
    char res[length_of_str]{};
    for (int i = 0; i < counter_of_words; ++i)
    {
        strcat(res, words[i]);
    }
    std::cout << res;
}