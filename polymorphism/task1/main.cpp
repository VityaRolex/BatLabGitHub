#include <vector>
#include <iostream>
#include <string>
#include "student.h"
#include "professor.h"
int main()
{ 
    std::vector<Person*> arr; 
    int c; 
    bool run=true;
    while(run){ 
    std::cout<<"1. Ввести студента \n2. Ввести преподавателя \n3. Вывести студентов \n4. Вывести преподавателей \n5. Выход \nВаш выбор: "; 
    std::cin>>c; 
    std::cin.ignore(1,'\n');
    if(c==1)
    { 
        std::string f; 
        int k,g; 
        std::cout<<"ФИО: "; 
        std::getline(std::cin,f); 
        std::cout<<"Курс: "; 
        std::cin>>k; 
        std::cout<<"Группа: ";
        std::cin>>g; 
        std::cin.ignore(1,'\n');
        arr.push_back(new Student(f.c_str(),k,g)); 
    }
    else if(c==2)
    { 
        std::string f,d; 
        std::cout<<"ФИО: "; 
        std::getline(std::cin,f); 
        std::cout<<"Кафедра: "; 
        std::getline(std::cin,d); 
        arr.push_back(new Professor(f.c_str(),d.c_str()));
    }
    else if(c==3)
    { 
        std::cout<<"Студенты:\n"; 
        for(auto*p:arr) 
        {
            if(auto*s=dynamic_cast<Student*>(p))
            { 
                s->print(std::cout),std::cout<<" "; 
            }
        }
    }
    else if(c==4)
    { 
        std::cout<<"Преподаватели:"; for(auto*p:arr) 
        {
            if(auto*r=dynamic_cast<Professor*>(p)) 
            {
                r->print(std::cout),std::cout<<" "; 
            }
        }
    }
    else if(c==5) 
        {
            run=false;
        } 
    }

    return 0; 
}