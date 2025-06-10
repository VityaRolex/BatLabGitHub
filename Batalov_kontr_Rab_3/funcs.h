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


void copyArr(Student * arr, int length, Student *& temp_arr)
{
    temp_arr = new Student[length];
    for (int i = 0; i < length; ++i)
    {
        strcpy(temp_arr[i].name, arr[i].name);
        temp_arr[i].group = arr[i].group;
        temp_arr[i].grade = arr[i].grade;
    }
}

void inputIntegerValue(int & element)
{
    double cinTemp{};
    std::cin >> cinTemp;
    while (std::cin.fail() || cinTemp - static_cast<int32_t>(cinTemp) != 0)
 {
    if(cinTemp - static_cast<int>(cinTemp) != 0)
    {
        std::cout << "it's very funny, and now enter INTEGER value \n";
    }
    if (std::cin.fail() || element > 5 || element <= 0)
    {
    std::cout << "It's not funny, be more serious and try again \n";
    std::cin.clear();
    std::cin.ignore();
    }
    std::cin >> cinTemp;
  }
  element = cinTemp;
}


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
    char temp_str[30]{};
    char str[30]{};
    std::cin >> str;
    for (int i = 0; i < length; ++i)
    {
        strcpy(temp_str, arr[i].name);
        if (strcmp(str,strtok(temp_str, " ")) == 0)
        {
            std::cout << arr[i].name << ' ' << arr[i].group << ' '  << arr[i].grade << '\n';  
            return;    
        }
        strcpy(temp_str, "");
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
    int temp_group{};
    int count{};
    int k{};
    while (k != length)
    {
        temp_group = arr[k].group;
        count += 1;
        temp_grade +=arr[k].grade;
        if (arr[k+1].group != temp_group || k == length - 1)
        {
            std::cout << "Average of group number " << temp_group << " is " << temp_grade/count << '\n';
            count = 0;
            temp_grade = 0;
        }
        ++k;
    }
       
}


void outputInFile(Student * arr, int length, std::ostream &fout)
{
    for (int i = 0; i < length; ++i)
    {
        fout << arr[i].name << ';' << arr[i].group << ';' << arr[i].grade << '\n';
    }
}