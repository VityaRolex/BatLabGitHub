#ifndef STUDENT2_H
#define STUDENT2_H
#include "student1.h"


class Student2 : public Student1 {
int grades2[5];
public:
Student2(const std::string&, int, int, int, const int*, const int*);
Student2(const Student2&);


int getGrade2(int i) const { return grades2[i]; }
void setGrade2(int i, int v) { grades2[i] = v; }


double avg() const override;
friend std::ostream& operator<<(std::ostream&, const Student2&);
};
#endif