#ifndef MYSTRING_H
#define MYSTRING_H
#include<cstring>
#include<iostream>

class Mystring
{
    char* start;
    size_t length;
public:
Mystring(size_t length);
Mystring();
Mystring(const char* init)
{
    this->length = strlen(init);
    this->start = new char[length + 1];
    strcpy(this->start, init);
}
~Mystring()
{
    delete []this->start;               
    this->start = nullptr;
    this->length = 0;
    //std::cout << "Mystring has been deleted";
}
Mystring(const Mystring& init)
{
    this->length = init.length;
    this->start = new char[this->length + 1];
    strcpy(this->start, init.start);
}
void get_start(char* buffer);
size_t get_length();
Mystring& operator =(const Mystring& init);
const Mystring operator +(const Mystring& rhs);
bool operator ==(const Mystring& rhs);
int operator <=(const Mystring& rhs);
const Mystring operator+(const char* rhs);
size_t find_first_of(const Mystring& search);
size_t find_first_not_of(const Mystring& search);
Mystring reverse();
size_t find_last_of(const Mystring& search);
size_t find_last_not_of(const Mystring& search);
Mystring operator +=(const Mystring& init);
Mystring substr(size_t length, size_t start = 0);
};

std::ostream& operator <<(std::ostream& out, Mystring& a);

#endif