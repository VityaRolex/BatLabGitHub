#include <fstream>
#include <iostream>
#include <string>


int main()
{
    int counter{};
    int number{};
    std::string temp;
    std::ifstream fin;
    std::ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt", std::ios::app);
    while(fin>>number)
    {
        ++counter;
    }
    int * arr = new int[counter];
    fin.seekg(0);
    int i = 0;
    while(fin>>number)
    {
        arr[i] = number;
        ++i;
    }

    std::cout << counter;
    return 0;
}