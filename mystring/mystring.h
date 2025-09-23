#ifndef MYSTRING_H
#define MYSTRING_H
#include<cstring>
#include<iostream>

class Mystring
{
    char* start;
    size_t length;
public:

Mystring(char* init = nullptr)
{
    this->length = strlen(init);
    this->start = new char[length];
    strcpy(this->start, init);
}
~Mystring()
{
    delete []this->start;
    //std::cout << "Mystring has been deleted";
}
Mystring(const Mystring& init)
{
    this->length = init.length;
    this->start = new char[this->length];
    strcpy(this->start, init.start);
}
Mystring& operator =(const Mystring& init);
const Mystring operator +(const Mystring& rhs);
friend std::ostream& operator <<(std::ostream& out, const Mystring& a);
bool operator ==(const Mystring& rhs);
int operator <=(const Mystring& rhs)
{
    return strcmp(this->start, rhs.start) <= 0;
}
};


#endif