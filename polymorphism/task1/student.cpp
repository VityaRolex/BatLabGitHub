#include "student.h"
Student::Student(const char* fio,int c,int g):Person(fio),course(c),group(g){}
Student::Student(const Student&o):Person(o),course(o.course),group(o.group){}
void Student::setCourse(int c){course=c;} 
void Student::setGroup(int g){group=g;}
int Student::getCourse()const{return course;} 
int Student::getGroup()const{return group;}
void Student::print(std::ostream& os)const
{
    os<<"Student: "; 
    Person::print(os); 
    os<<" course="<<course<<" group="<<group; 
}
Person* Student::clone()const{ return new Student(*this);}
Student::Student(Student&& rhs): Person(rhs)
{
    course = rhs.course;
    group = rhs.group;
    rhs.course = 0;
    rhs.group = 0;
}
Student& Student::operator=(const Student& rhs)
{
    if(this != &rhs)
    {
        *((Person*)this) = rhs;
        group = rhs.group;
        course = rhs.course;
    }
    return *this;
}
Student& Student::operator=(Student&& rhs)
{
    if(this != &rhs)
    {
        *((Person*)this) = rhs;
        group = rhs.group;
        course = rhs.course;
        rhs.group = 0;
        rhs.course = 0;
    }
    return *this;
}