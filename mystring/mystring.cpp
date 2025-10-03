#include"mystring.h"

Mystring& Mystring::operator =(const Mystring& init)
{
    if(this != &init)
    {
        delete []this->start;
        this->start = new char[init.length];
        this->length = init.length;
        strcpy(this -> start, init.start);
    }
    return *this;
}


bool Mystring::operator ==(const Mystring& rhs)
{
    
    return strcmp(this->start, rhs.start) == 0;
}

int Mystring::operator <=(const Mystring& rhs)
{
    return strcmp(this->start, rhs.start) <= 0;
}

const Mystring Mystring::operator+(const char* rhs)
{
    return *this + Mystring(rhs);
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


size_t Mystring::find_first_of(const Mystring& search)
{
    size_t res{std::string::npos};
    char* p = strpbrk(this->start, search.start);
    if(p)
    {
        res = p - this->start;
    }
    return res;
}

size_t Mystring::find_first_not_of(const Mystring& search)
{
    size_t res{std::string::npos};
    char* p = this->start;
    while(p - this->start < this->length)
    {
        if(!strchr(search.start, *p))
        {
            res =  p - this->start;
            break;
        }
        ++p;
    }

    return res;
}

Mystring Mystring::reverse()
{
    Mystring res("");
    size_t length = this->length - 1;
    res.length = length + 1;
    char* tmp = new char[2];
    tmp[1] = '\0';
    while(length >= 0)
    {
        tmp[0] = (this->start)[length];
        res = res + tmp;
        --length;
    }
    return res;
}

size_t Mystring::find_last_of(const Mystring& search)
{
    Mystring tmp = this->reverse();
    return tmp.find_first_of(search);
}

size_t Mystring::find_last_not_of(const Mystring& search)
{
    Mystring tmp = this->reverse();
    return tmp.find_first_of(search);
}

Mystring Mystring::operator +=(const Mystring& init)
{
    return *this + init;
}


Mystring Mystring::substr(size_t length, size_t start = 0)
{
    char * res = new char[length];
    for(int i = 0; i < length; ++i)
    {
        res[i] = this->start[start + i];
    }
    return Mystring(res);
}