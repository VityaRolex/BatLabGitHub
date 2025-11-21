#include "student1.h"
Student1::Student1(const std::string& n, int c, int g, int rb, const int* arr)
: Student(n,c,g,rb){ for(int i=0;i<4;i++) grades1[i]=arr[i]; }


Student1::Student1(const Student1& o)
: Student(o){ for(int i=0;i<4;i++) grades1[i]=o.grades1[i]; }


double Student1::avg() const{
double s=0; for(int x:grades1) s+=x; return s/4;
}


std::ostream& operator<<(std::ostream& os, const Student1& s){
os << static_cast<const Student&>(s) << " Grades1: ";
for(int x:s.grades1) os<<x<<" "; return os;
}