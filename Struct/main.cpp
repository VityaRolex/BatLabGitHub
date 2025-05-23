#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstdlib>


struct Student {
    std::string surname;
    int marks [3];
};

void InputConcreteStudent(Student& student, int number)
{
    std::cout << "input surname of the " << number << "th student \n";
    std::getline(std::cin, student.surname);
    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << "input his " << i+1 << "th mark \n";
        std::cin >> student.marks[i];
        if (student.marks[i] < 0 || student.marks[i] > 10)
        {
            throw std::invalid_argument("Marks must be non-negative and smaller or equal than 10");
        }
    }
    std::cin.ignore();
}


void InputAllStudents(Student * students, int size)
{
    for (size_t i = 0; i < size; ++i)
    {
        InputConcreteStudent(students[i], i + 1);
    }
}


double CalculateAverageOfArray(int * arr, int size)
{
    double result = 0;
    for (size_t i = 0; i < size; ++i)
    {
        result += arr[i];
    }
    return result/size;
}

void OutputConcreteStudent(Student& student)
{
    std::cout << student.surname << '\n';
    for (int i = 0; i < 3; ++i)
    {
        std::cout << student.marks[i] << ' ';
    }
    std::cout << '\n';
}


void OutputAllStudents(Student * students, int size)
{
    for (int i = 0; i < size; ++i)
    {
        OutputConcreteStudent(students[i]);
    }
}

int CompBySurname(const void * stud1, const void * stud2)
{
    return stricmp((((Student*)stud1)->surname).c_str(),(((Student*)stud2)->surname).c_str());
}

void SortBySurname(Student * arr, int size)
{
    qsort(arr, size, sizeof(Student), CompBySurname);
}

int main()
{
    int size{};
    std::cout <<  "Input amount of students \n";
    try
    {
        std::cin >> size;
    if (size <= 0)
    {
        throw std::invalid_argument("size must be positive");
    }
    Student * arrOfStudents = new Student [size];
    std::cin.ignore();
    InputAllStudents(arrOfStudents, size);
    OutputAllStudents(arrOfStudents, size);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    

    return 0;
}