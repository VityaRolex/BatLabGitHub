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


bool Mystring::operator ==(const Mystring& rhs)
{
    
    return strcmp(this->start, rhs.start) == 0;
}


const Mystring Mystring::operator +(const Mystring& rhs)
{
    char * res = new char[this->length + rhs.length];
    strcpy(res, this->start);
    strcat(res, rhs.start);
    return(Mystring(res));
}

std::ostream& operator <<(std::ostream& out, const Mystring& a)
{
    for(int i = 0; i < a.length;++i)
    {
        out << a.start[i];
    }
    return out;
}

