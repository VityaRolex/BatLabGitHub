#ifndef STUDENT1_H
#define STUDENT1_H
#include "student.h"


class Student1 : public Student {
protected:
int grades1[4];
public:
Student1(const std::string&, int, int, int, const int*);
Student1(const Student1&);


int getGrade1(int i) const { return grades1[i]; }
void setGrade1(int i, int v) { grades1[i] = v; }


double avg() const override;
friend std::ostream& operator<<(std::ostream&, const Student1&);
};
#endif