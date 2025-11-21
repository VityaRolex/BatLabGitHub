#include "student2.h"
Student2::Student2(const std::string& n, int c, int g, int rb, const int* a1, const int* a2)
: Student1(n,c,g,rb,a1){ for(int i=0;i<5;i++) grades2[i]=a2[i]; }


Student2::Student2(const Student2& o)
: Student1(o){ for(int i=0;i<5;i++) grades2[i]=o.grades2[i]; }


double Student2::avg() const{
double s1=0; for(int x:grades1) s1+=x;
double s2=0; for(int x:grades2) s2+=x;
return (s1/4 + s2/5) / 2;
}


std::ostream& operator<<(std::ostream& os, const Student2& s){
os << static_cast<const Student1&>(s) << " Grades2: ";
for(int x:s.grades2) os<<x<<" "; return os;
}