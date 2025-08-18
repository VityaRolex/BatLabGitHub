#include <iostream>
#include <cstring>

/*
char returnLetter(int32_t number)
{
    char Alfa[68]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','+','-','*','=','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','"','?'};
    return Alfa[number];
}
*/

char returnLetter(int number, char * KEY)
{
    return KEY[number - 1];
}


/*
int32_t returnNumber(char Symbol)
{
    char Alfa[68]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','+','-','*','=','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','"','?'};
   for (int32_t i = 0; i < 68; ++i)
    {
        if (Symbol == Alfa[i])
        {
            return i;
        }
    }
    return 98;
}
*/

int returnNumber(char Symbol, char * KEY)
{
    int lenght = strlen(KEY);
    for (int i = 0; i < lenght; ++i)
    {
        if (Symbol == KEY[i])
        {
            return i + 1;
        }
    }
    return 100;
}



int defineLenght(char* input, char * KEY)
{
    int temp = strlen(KEY);
    int32_t lenght{1};
    while (returnNumber(input[lenght], KEY) >= 0 && returnNumber(input[lenght], KEY) < temp)
    {
        lenght += 1;
    }
    return lenght;
}





void dechifr(char* input, char* result, char * KEY)
{
    for (int32_t i = 0; i <= (defineLenght(input, KEY)-1)/2; ++i)
    {
        result[i] = returnLetter(returnNumber(input[2*i], KEY)*returnNumber(input[2*i + 1], KEY) % strlen(KEY), KEY);
    }
}


void inputChifr(char* input, char * KEY)
{
    std::cout << "Input Chifr\n";
    int64_t i{};
    std::cin >> input[i];
    while(returnNumber(input[i], KEY) < strlen(KEY))
    {
        i+=1;
        std::cin >> input[i];
    }
}


int chifrsymbol(char * output, int32_t number, int32_t letter, int32_t& l, char * KEY)
{
    for (; l< strlen(KEY) - 1; ++l)
    {
        for (int32_t j = 2; j < strlen(KEY) - 1; ++j)
        {
            if ((l*j) % strlen(KEY) == letter)
            {
                output[2*number] = returnLetter(l, KEY);
                output[2*number + 1] = returnLetter(j, KEY);
                return 0;
            }
        }
    }
    if (returnNumber(output[2*number], KEY) > strlen(KEY) - 1) {
        l = 2;
        chifrsymbol(output, number, letter, l, KEY);
        return 0;
    }
}


void chifr (char* input, char* output, char * KEY)
{
    int32_t l{2};
    for (int32_t i = 0; i < defineLenght(input, KEY); ++i)
    {
        chifrsymbol(output, i, returnNumber(input[i], KEY), l, KEY);
        l= rand() % (strlen(KEY) - 3) + 2;
    }

}


int main()
{
    char KEY[75]{};
    const int MAX_LENGHT_OF_INPUT{100000};
    const int MAX_LENGHT_OF_OUTPUT{100000};
    char input[MAX_LENGHT_OF_INPUT]{}; 
    char output[MAX_LENGHT_OF_OUTPUT]{};
    int switchInt{};
    std::cout << "Input KEY";
    std::cin >> KEY;
    inputChifr(input, KEY);
    while(true)
    {
    std::cout << "Do You want to chifr(1) or dechifr(2)? \n";
    std::cin >> switchInt;
    switch (switchInt)
    {
    case 1:
    {
        chifr(input, output, KEY);
        break;
    }
    case 2:
    {
        dechifr(input, output, KEY);
        break;
    }
    
    default:
        break;
    }
    for (int32_t i=0; i < MAX_LENGHT_OF_OUTPUT; ++i)
    {
        std::cout << output[i];
        input[i] = output[i];
        output[i] = 0;
    }
    std::cout << '\n';

    }

    return 0;
}


//UQVDSIXTQKXSRKWIWCNIUKXPNO
//UQVDSIXTQKXSRKWIXJVJXQRNTESN
//WKMFUKXPNOVVNITRWVXVNE