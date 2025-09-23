#include"mystring.h"

Mystring& Mystring::operator =(const Mystring& init)
{
    if(this != &init)
    {
        delete []this->start;
        this->start = new char[init.length];
        this->length = init.length;
        for(int i = 0; i < length; ++i)
        {
            (this->start)[i] = init.start[i];
        }
    }
    return *this;
}

const Mystring& Mystring::operator +(const Mystring& rhs)
{
    size_t length = this->length + rhs.length;
    char* res = new char[length];
    int counter{};
    for(int i = 0; i < this->length; ++i)
    {
        res[counter++] = this->start[i];
    }
    for(int i = 0; i < rhs.length; ++i)
    {
        res[counter++] = rhs.start[i];
    }
    return Mystring(res, length);
}

std::ostream& operator <<(std::ostream& out, const Mystring& a)
{
    for(int i = 0; i < a.length;++i)
    {
        out << a.start[i];
    }
    return out;
}

