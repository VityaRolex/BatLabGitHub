#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>


class Student {
protected:
const int id;
static int next_id;
std::string name;
int course;
int group;
const int recordBook;
public:
Student(const std::string& name, int course, int group, int recordBook);
Student(const Student& other);
virtual ~Student() = default;


int getId() const { return id; }
const std::string& getName() const { return name; }
int getCourse() const { return course; }
int getGroup() const { return group; }
int getRecordBook() const { return recordBook; }


void setName(const std::string& n) { name = n; }
void setCourse(int c) { course = c; }
void setGroup(int g) { group = g; }


virtual double avg() const = 0;
friend std::ostream& operator<<(std::ostream&, const Student&);
};
#endif