#include"header.h"


void inputVector(std::vector<int>& v, std::istream& in)
{
    std::cout << "Введите числа в вектор через пробел или через enter, когда закончите, введите любой нечисловой символ.\n";
    int buffer{};
    while(in >> buffer)
    {
        v.push_back(buffer);
    }
}


void clearInput(std::istream& in)
{
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int countSum(std::vector<int>& v)
{
    int res{};
    for (int i{}; i < v.size(); ++i)
    {
        res += v.at(i);
    }
    return res;
}


size_t countNumsEqualTo(std::vector<int>& v, int n)
{
    size_t res{};
    for (int i{}; i < v.size(); ++i)
    {
        if (v.at(i) == n)
        {
            ++res;
        }
    }
    return res;
}


int countAverage(std::vector<int>& v)
{
    return (countSum(v))/v.size();
}


void changeZerosToAverage(std::vector<int>& v)
{
    int av = countAverage(v);
    for(int i{}; i < v.size(); ++i)
    {
        if (v.at(i) == 0)
        {
            v.at(i) = av;
        }
    }
}


int countSumFromAToB(std::vector<int>& v, size_t A, size_t B)
{
    int res{};
    if (A > B || A < -1 || B > v.size() + 1)
    {
        throw std::runtime_error("a");
    }
    for (int i{A}; i < B; ++i)
    {
        res += v.at(i);
    }
    return res;
}


void addToEveryElementOfVectorSumOfVectorFromAToB(std::vector<int>& v, size_t A, size_t B)
{
    int sum = countSumFromAToB(v, A, B);
    for(int i{}; i < v.size(); ++i)
    {
        v.at(i) += sum;
    }
}


void changeEvenToMaxMinusMin(std::vector<int>& v)
{
    int max{v.at(0)};
    int min{v.at(0)};
    int minus{};
    for (int i{}; i < v.size(); ++i)
    {
        if (v.at(i) < min)
        {
            min = v.at(i);
        }
        if (v.at(i) > max)
        {
            max = v.at(i);
        }
    }
    minus = max - min;
    for (int i{}; i < v.size(); ++i)
    {
        if (std::abs(v.at(i)) % 2 == 0)
        {
            v.at(i) = minus;
        }
    }
}


void deleteAllEqualOnModuleSaufFirst(std::vector<int>& v)
{
    for (int i{}; i < v.size(); ++i)
    {
        for (int j{i + 1}; j < v.size(); ++j)
        {
            if (v.at(j) == v.at(i))
            {
                v.erase(v.begin() + j);
                --j;
            }
        }
    }
}


void openStream(std::ifstream& in, const char* name)
{
    in.close();
    in.open(name, std::ios::in);
    if(!in.is_open())
    {
        throw std::runtime_error("b");
    }
    if(in.peek() == EOF)
    {
        throw std::runtime_error("c");
    }
}


void readStringsFromFile(std::vector<std::string>& v, std::ifstream& in)
{
    std::string temp{};
    while(in.peek() != EOF)
    {
        std::getline(in, temp);
        v.push_back(temp);
    }
}


void sortVector(std::vector<std::string>& v)
{
   
}


void printVector(std::vector<std::string>& v)
{
    for(int i{}; i < v.size(); ++i)
    {
        std::cout << v.at(i) << '\n';
    }
}


void printOnLetter(std::vector<std::string>& v, char c)
{
    for(int i{}; i < v.size(); ++i)
    {
        if(v.at(i)[0] == c)
        {
            std::cout << v.at(i) << '\n';
        }
    }
}


void deleteOnLetter(std::vector<std::string>& v, char c)
{
    for(int i{}; i < v.size(); ++i)
    {
        if(v.at(i)[0] == c)
        {
            v.erase(v.begin() + i);
            --i;
        }
    }
}


bool operator <(Time& left, Time& right)
{
    if (left.hours > right.hours)
    {
        return true;
    }
    if (left.hours == right.hours && left.minutes < right.minutes)
    {
        return true;
    }
    return false;
}


bool operator ==(Time& l, Time& r)
{
    return (r.hours == l.hours && r.minutes == l.minutes);
}


bool operator <=(Time& l, Time& r)
{
    return (l < r || l == r);
}


bool operator !=(Time& l, Time& r)
{
    return !(l == r);
}





