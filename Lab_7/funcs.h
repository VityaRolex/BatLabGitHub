#include <iostream>
#include <string>


bool isWordPol(std::string word, int length, int i)
{
    if(word[i] != word[length - 1 - i])
    {
        return false;
    }
    else if (length - 1 - 2*i <= 2)
    {
        return true;
    }
    return isWordPol(word, length, i+1);
}




void sortLatinWords(std::string str)
{
    int count_of_words{};
    int k{};
    std::string arr_of_words[str.length()];
    int count_of_alphaWords{};
    for(int i = 0; i < str.length(); ++i)
    {
      for (int j = i; j < str.length(); ++j)
        {
            if  (( j == str.length() - 1) || (((isalpha(str[j]) && str[j] != ' ') && ( (!isalpha(str[j+1]) || str[j + 1] == ' '))) || ((!isalpha(str[j]) || str[j] == ' ') && (isalpha(str[j+1]) && str[j + 1] != ' '))))
            {
                arr_of_words[k] = str.substr(i, j - i + 1);
                i = j;
                j = str.length();
                if(isalpha(str[i]) && str[i] != ' ' && isWordPol(arr_of_words[k], arr_of_words[k].length(), 0))
                {
                    ++count_of_alphaWords;
                }
                ++k;
                ++count_of_words;
            }
        }
    }


    k = 0;
    int * alphaWords = new int [count_of_alphaWords];
    for (int i = 0; i < count_of_words; ++i)
    {
        if ((isalpha(arr_of_words[i][0]) && arr_of_words[i][0] != ' ') && isWordPol(arr_of_words[i], arr_of_words[i].length(), 0))
        {
            alphaWords[k++] = i;
        }
    }



    k = 0;
    while (k != count_of_alphaWords - 1)
    {
        if(arr_of_words[alphaWords[k]] > arr_of_words[alphaWords[k + 1]])
        {
            std::swap(arr_of_words[alphaWords[k]], arr_of_words[alphaWords[k + 1]]);
            k = 0;
        }
        else
        {
            ++k;
        }
    }

    for (int i = 0; i < count_of_words; ++i)
    {
        std::cout << arr_of_words[i];
    }



   
}
