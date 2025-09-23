#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>

class Mystring
{
    char* start;
    size_t length;
public:

Mystring(char* init = nullptr, size_t length = 0)
{
    this->length = length;
    this->start = new char[length];
    for(int i = 0; i < length; ++i)
    {
        (this->start)[i] = init[i];
    }
}
~Mystring()
{
    delete []this->start;
    std::cout << "Mystring has been deleted";
}
Mystring(const Mystring& init)
{
    this->length = init.length;
    this->start = new char[this->length];
    for(int i = 0; i < length; ++i)
    {
        (this->start)[i] = init.start[i];
    }
}
Mystring& operator =(const Mystring& init);
const Mystring& operator +(const Mystring& rhs);
friend std::ostream& operator <<(std::ostream& out, const Mystring& a);
};


#endif