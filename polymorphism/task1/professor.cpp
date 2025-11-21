#include "professor.h"
#include <cstring>
static char* str_dup2(const char*s)
{ 
    if(!s)
    {
        return nullptr;
    } 
    size_t n=strlen(s)+1; 
    char*d=new char[n]; 
    memcpy(d,s,n);
    return d; 
}
Professor::Professor(const char*f,const char*d):Person(f){ dept=str_dup2(d);}
Professor::Professor(const Professor&o):Person(o){ dept=str_dup2(o.dept);}
Professor::~Professor(){ delete[] dept; }
Professor::Professor(Professor&& rhs) : Person(rhs)
{
    dept = rhs.dept;
    rhs.dept = nullptr;
}
Professor& Professor::operator = (const Professor& rhs)
{
    if(this != &rhs)
    {
        *((Person*)this) = rhs;
        dept = str_dup2(rhs.dept);
    }
    return *this;
}
Professor& Professor::operator = (Professor&& rhs)
{
    if(this != &rhs)
    {
        *((Person*)this) = rhs;
        dept = rhs.dept;
        rhs.dept = nullptr;
    }
    return *this;
}
void Professor::setDepartment(const char*s)
{ 
    delete[] dept; 
    dept = str_dup2(s);
}
const char* Professor::getDepartment()const{return str_dup2(dept);}
void Professor::print(std::ostream&os)const
{ 
    os<<"Professor: "; 
    Person::print(os); 
    os<<" dept="<<(dept?dept:"?"); 
}
Person* Professor::clone()const{ return new Professor(*this);}