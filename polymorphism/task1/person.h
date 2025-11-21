#ifndef PERSON_H
#define PERSON_H
#include <iostream>
class Person {
protected:
char* fio;
public:
Person(const char* fio = nullptr);
Person(const Person&);
Person(Person &&);
virtual ~Person();
Person& operator = (const Person& rhs);
Person& operator = (Person&& rhs);
void setFio(const char*);
const char* getFio() const;
virtual void print(std::ostream&) const;
virtual Person* clone() const = 0;
virtual void erase();
};
#endif