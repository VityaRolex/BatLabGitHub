#include <iostream>
#include <vector>
#include "student1.h"
#include "student2.h"


int main(){
std::vector<Student*> arr;


int g1[4] = {5,4,4,5};
int g2[4] = {3,4,5,3};
int g3[5] = {4,5,5,4,5};


arr.push_back(new Student1("Ivanov",2,3,1001,g1));
arr.push_back(new Student2("Petrov",2,3,1002,g2,g3));


std::cout << "--- Students ---\n";
for(auto p:arr){
std::cout << *p << " Avg=" << p->avg() << "\n";
}


for(auto p:arr) delete p;
return 0;
}