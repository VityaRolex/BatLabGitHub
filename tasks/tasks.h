#include <iostream>
#include <cstring>

void EnterString(char*string, int maxLenght)
{
    std::cin.getline(string, maxLenght);
}




void Task1(char * string, int maxLenght)
{
    char result[150]{};
    setlocale(LC_ALL, "RU");
    std::cout << "Ведите имя \n";
    std::cin.getline(string, maxLenght);
    strcat(result, "\n Привет, ");
    strcat(result, string);
    strcat(result, "!!! Пора сдать все лабы!");
    std::cout << result;
}


void Task2 (char * string, char * divides)
{
    int counter{};
    char * pch = strtok(string, divides);
    while (pch != NULL)
    {
        counter += 1;
        pch = strtok(NULL, divides);
    }
    if (counter == 0)
    {
        throw "Impossible to count words in empty string";
    }
    std::cout << "String contains " << counter + 1 << " words";
}


void Task3 (char * string, char * divides)
{
    bool out{};
    char * pch = strtok(string, divides);
    while (pch != NULL)
    {
        if (*pch == 'A')
        {
            std::cout << pch << '\n';
            out = 1;
        }
        pch = strtok(NULL, divides);
    }
    if (!out)
    {
        std::cout << "string doesn't contain words with first letter A";
    }
}


void Task4(char * string, int maxLenght)
{
    int res{};
    for (size_t i = 0; i < strlen(string); ++i)
    {
        if (string[i] > '0' && string[i] <= '9')
        {
            res += string[i] - '0';
        }
    }
    std::cout << res;
}


void Task5(char * string, char * divides)
{
    char * pch = strtok(string, divides);
    int lenght{strlen(pch)};
    char * res = pch;
    while (pch != NULL)
    {
        if ( lenght > strlen(pch))
        {
            lenght = strlen(pch);
            res = pch;
        }
        pch = strtok(NULL, divides);
    }
    std::cout << res << '\n';
}