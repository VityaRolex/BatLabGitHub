#include <iostream>
#include <string>


bool isWordPol(std::string word, int length, int i)
{
    if (word.length() == 1)
    {
        return false;
    }
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




void makeWordArr(std::string str, std::string * arr_of_words, int& count_of_words, int& count_of_alphaWords)
{
    int  k{};
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
}


void makeArrOfAlfaIdx(int *& alphaWords, int count_of_alphaWords, std::string * arr_of_words, int count_of_words)
{
    int k{};
    alphaWords = new int [count_of_alphaWords];
    for (int i = 0; i < count_of_words; ++i)
    {
        if ((isalpha(arr_of_words[i][0]) && arr_of_words[i][0] != ' ') && isWordPol(arr_of_words[i], arr_of_words[i].length(), 0))
        {
            alphaWords[k++] = i;
        }
    }
}


void sortAlphaWords(int * alphaWords, int count_of_alphaWords, std::string * arr_of_words)
{
    int k{};
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
}


void makeResStr(std::string& res, std::string * arr_of_words, int count_of_words)
{
    for (int i = 0; i < count_of_words; ++i)
    {
        res+= arr_of_words[i];
    }
}


void sortLatinWords(std::string str)
{
    int count_of_words{};
    int k{};
    std::string arr_of_words[str.length()];
    int count_of_alphaWords{};
    int * alphaWords{};
    std::string res("");
    makeWordArr(str, arr_of_words, count_of_words, count_of_alphaWords);
    makeArrOfAlfaIdx(alphaWords, count_of_alphaWords, arr_of_words, count_of_words);
    sortAlphaWords(alphaWords, count_of_alphaWords, arr_of_words);
    makeResStr(res, arr_of_words, count_of_words);
    std::cout << res;
}
