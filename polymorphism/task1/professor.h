#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "person.h"
class Professor: public Person{
char* dept;
public:
Professor(const char*,const char*);
Professor(const Professor&);
Professor(Professor&&);
~Professor();
Professor& operator = (const Professor& rhs);
Professor& operator = (Professor&& rhs);
void setDepartment(const char*);
const char* getDepartment() const;
void print(std::ostream&) const override;
Person* clone() const override;
};
#endif