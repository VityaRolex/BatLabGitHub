#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
class Student: public Person{
int course, group;  //
public:
Student(const char*,int,int);
Student(const Student&);
Student(Student&&);
Student& operator=(const Student&);
Student& operator=(Student&&);
void setCourse(int); void setGroup(int);
int getCourse()const; int getGroup()const;
void print(std::ostream&) const override;
Person* clone() const override;
};
#endif