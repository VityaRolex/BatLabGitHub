#include<iostream>
#include<vector>
#include<exception>

template<typename T>
std::ostream& operator << (std::ostream& os, std::vector<T>& v)
{
    os << '(';
    for (int i = 0; i < v.size(); ++i)
    {
        os << v.at(i)  << ' ';
    }
    os << '\b' << ')' << '\n';
    return os;
}

std::vector<std::vector<int>> mulMtr(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b)
{
    int aRows = a.size();
    int aCols = a.at(0).size();
    int bRows = b.size();
    int bCols = b.at(0).size();
    if (aCols != bRows)
    {
        throw std::invalid_argument("multiplying isn't possible");
    }
    std::vector<std::vector<int>> result(aRows, std::vector<int>(bCols));
    for (int i = 0; i < aRows; ++i)
    {
        for(int j = 0; j < bCols; ++j)
        {
            for(int s = 0; s < aCols; ++s)
            {
                result.at(i).at(j) += a.at(i).at(s) * b.at(s).at(j);
            }
        }
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> mtr(3, std::vector<int>(4));
    std::cout << mtr;
    return 0;
}


//в векторе удалить все нули, все отрицательные заменить на 123, все нечётные отсортировать по возрастанию, 

void task(std::vector<int>& v)
{
    std::vector<int> oddIdx;
    for(int i = 0; i < v.size(); ++i)
    {
        if(v.at(i) == 0)
        {
            v.erase(v.begin() + i);
        }
        if(v.at(i) < 0)
        {
            v.emplace(v.begin() + i, 123);
        }
        if(v.at(i) % 2 == 0)
        {
            v.push_back(i);
        }
    }
    v.shrink_to_fit();
    oddIdx.shrink_to_fit();
    
}