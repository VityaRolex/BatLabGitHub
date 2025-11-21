#include "student.h"
int Student::next_id = 1;


Student::Student(const std::string& n, int c, int g, int rb)
: id(next_id++), name(n), course(c), group(g), recordBook(rb) {}


Student::Student(const Student& o)
: id(next_id++), name(o.name), course(o.course), group(o.group), recordBook(o.recordBook) {}


std::ostream& operator<<(std::ostream& os, const Student& s){
os << "ID=" << s.id << " Name=" << s.name
<< " Course=" << s.course << " Group=" << s.group
<< " RecordBook=" << s.recordBook;
return os;
}