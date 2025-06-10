#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

struct Student
{
    char name[30];
    int group;
    double grade;
};


void makeStudArr(Student *& arr, std::fstream & in, int& count_of_studs)
{
    std::string str;
    while(getline(in, str))
    {
        count_of_studs += 1;
    }
    in.clear();
    in.seekg(std::ios::beg);
    arr = new Student[count_of_studs];
    for (int i = 0; i < count_of_studs; ++i)
    {
        in.getline(arr[i].name, 30, ';');
        getline(in,str, ';');
        arr[i].group = stoi(str);
        getline(in,str,'\n');
        arr[i].grade = stof(str);
    }
}



int compareStuds(const void* elem1, const void* elem2)
{
    return strcmp(((Student*)elem1)->name, ((Student*)elem2)->name);
}
void SortArr(Student * arr, int length)
{
    qsort(arr,  length, sizeof(Student), compareStuds);
}


void searchStud(Student *arr, int length)
{
    char str[30]{};
    std::cin >> str;
    for (int i = 0; i < length; ++i)
    {
        if (str == arr[i].name)
        {
            std::cout << arr[i].name << ' ' << arr[i].group << ' '  << arr[i].grade;  
            return;    
        }
    }
    std::cout << "There isn't stud with this surname";
}

int compareByGroup(const void * elem1, const void * elem2)
{
    return ((Student *)elem1)->group - ((Student *)elem2)->group;
}


void sortByGroup(Student * arr, int length)
{
    qsort(arr, length, sizeof(Student), compareByGroup);
    for (int i = 0; i < length; ++i)
    {
        for (int j = i; j < length; ++j)
        {
            if (arr[i].group != arr[j].group)
            {
                SortArr(arr+i, j - i + 1);
            }
        }
    }
}


void AverageMarkOfGroups(Student * arr, int length)
{
    double temp_grade{};
    int temp_group{arr[0].group};
    int count{};
    int k{};
    while (k != length - 1)
    {
        if(arr[k].group != temp_group || k == length - 2)
        {
            std::cout << temp_grade/count;
            
        }
        else 
        {
            temp_grade += arr[k].grade;
            ++count;
        }
        }
        ++k;
}


void outputInFile(Student * arr, int length, std::ofstream &fout)
{
    for (int i = 0; i < length; ++i)
    {
        fout << arr[i].name << ';' << arr[i].group << ';' << arr[i].grade << '\n';
    }
}