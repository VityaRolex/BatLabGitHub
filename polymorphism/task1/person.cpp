#include "person.h"
#include <cstring>
static char* str_dup(const char* s)
{ 
    if(!s) 
    {
        return nullptr;
    } 
    size_t n = strlen(s)+1; 
    char* d = new char[n]; 
    memcpy(d,s,n); 
    return d; 
}
Person::Person(const char* s)
{ 
    fio=str_dup(s);
}
Person::Person(const Person& o)
{ 
    fio=str_dup(o.fio);
}
Person::~Person()
{ 
    delete[] fio; 
}
void Person::setFio(const char* s)
{
    delete[] fio; 
    fio=str_dup(s);
}
const char* Person::getFio() const 
{
    char* res = str_dup(fio);
    return res;
}
void Person::print(std::ostream& os) const
{ 
    os<<"FIO: "<<(fio?fio:"?"); 
}

void Person::erase()
{
    delete[] fio;
    fio = nullptr;
}

Person::Person(Person&& other)
{
    fio = str_dup(other.fio);
    other.erase();
}

Person& Person::operator=(const Person& rhs)
{
    if(this != &rhs)
    {
        delete [] fio;
        fio=str_dup(rhs.fio);
    }
    return *this;
}

Person& Person::operator=(Person&& rhs)
{
    if(this != &rhs)
    {
        delete [] fio;
        fio = rhs.fio;
        rhs.fio = nullptr;
    }
    return *this;
}

