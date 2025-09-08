#include "head.h"
void inputLength(int& length)
{
    std::cout << "Input Elements Count\n";
    std::cin >> length;
}

void consoleInputStudent(Student * arr, int length)
{
    for (int i{}; i < length; ++i)
    {
        std::cout << i+1 << ")";
        std::cout << "name-";
        std::cin >> arr[i].name;
        std::cout << "surname-";
        std::cin >> arr[i].surname;
        std::cout << "patronymic-";
        std::cin >> arr[i].patronymic;
        std::cout << "course-";
        std::cin >> arr[i].course;
        std::cout << "group-";
        std::cin >> arr[i].group;
        for (int j{}; j < 3; ++j)
        {
            std::cout << i+1 << "th mark-";
            std::cin >> arr[i].marks[j];
        }
    }
}



std::string GetOneWordFromFile(std::ifstream& in)
{
    std::string result{};
    char buffer{};
    while(in.get(buffer) && buffer != '\n' && buffer != ';')
    {
        result += buffer;
    }
    return result;
}




void fileInputInt(int* arr, int length, std::ifstream& file)
{
    for(int i{}; i < length; ++i)
    {
        arr[i] = stoi(GetOneWordFromFile(file));
    }
}

void fileInputDouble(double* arr, int length, std::ifstream& file)
{
    for(int i{}; i < length; ++i)
    {
        arr[i] = stof(GetOneWordFromFile(file));
    }
}





void fileInputStud(Student* arr, int length, std::ifstream& file)
{
    for(int i{}; i < length; ++i)
    {
        arr[i].course = stoi(GetOneWordFromFile(file));
        arr[i].group = stoi(GetOneWordFromFile(file));
        arr[i].surname = GetOneWordFromFile(file);
        arr[i].name = GetOneWordFromFile(file);
        arr[i].patronymic = GetOneWordFromFile(file);
        for(int j{}; j < 3; ++j)
        {
            arr[i].marks[j] = stoi(GetOneWordFromFile(file));
        }
    }
}


void makeRandArr(int * arr, int length)
{
    for(int i{}; i < length; ++i)
    {
        arr[i] = rand();
    }
}


bool compFunc(int a, int b)
{
    return a < b;
}


int countElems(std::ifstream& in)
{
    char buffer{};
    int length{};
    while (!in.eof())
    {
        buffer = in.get();
        if (buffer == ';' || buffer == '\n')
        {
            ++length;
        }
    }
    in.clear();
    in.seekg(std::ios::beg);
    return length;
}

int countStuds(std::ifstream& in)
{
    char buffer{};
    int length{};
    while (!in.eof())
    {
        buffer = in.get();
        if ( buffer == '\n')
        {
            ++length;
        }
    }
    in.clear();
    in.seekg(std::ios::beg);
    return length;
}




void countSort(Student* arr, int length, Student minElem, Student maxElem)
{
    //do nothing
}

void countSort(std::string* arr, int length, std::string minElem, std::string maxElem)
{
    //do nothing
}

void countSort(double* arr, int length, double minElem, double maxElem)
{
    //do nothing
}

void Data_type(int32_t& dataType)
{
    std::cout << "Select data type: 0 - integer numbers, 1 - strings, 2 - students, 3 - double numbers\n";
    std::cin >> dataType;
}



void ChooseMethods(int32_t& Method_Sort)
{
    std::cout << "Choose the sorting method\n\n";
    std::cout << "Bubble Sort O(n*n) - 0\n";
    std::cout << "Cocktail Shaker Sort O(n*n) - 1\n";
    std::cout << "Comb Sort O(n log n). - 2\n";
    std::cout << "Insertion Sort O(n*n) - 3\n";
    std::cout << "Selection Sort O(n*n)  - 4\n";
    std::cout << "Quick Sort O(n log n) - 5\n";
    std::cout << "Merge Sort O(n log n) - 6\n";
    std::cout << "Counting Sort(not for string and stud) O(n + k)\n";
    std::cout << "BogoSort O(n * n!) - 8\n";

    std::cin >> Method_Sort;
    if (Method_Sort < 0 || Method_Sort > 8)
    {
        throw std::runtime_error("Mistake in input sort");
    }
}

bool compFunc(std::string a, std::string b)
{
    return a < b;
}

bool EqualTwoArrs(int * arr1, int * arr2)
{
    bool flag[3]{};
    for (int i{}; i < 3; ++i)
    {
        for (int j{}; j < 3; ++j)
        {
            if (arr1[i] == arr2[j])
            {
                flag[j] = !flag[j];
            }
        }
    }
    return flag[0] && flag[1] && flag[2];
}

bool operator ==(Student a, Student b)
{
    return a.course == b.course && a.group == b.group && a.name == b.name && a.patronymic == b.patronymic && a.surname == b.surname && EqualTwoArrs(a.marks, b.marks);
}
bool compFuncBySurname(Student a, Student b)
{
    return a.surname + a.name + a.patronymic < b.surname + b.name + b.patronymic;
}

bool compFuncByCourse(Student a, Student b)
{
    return a.course < b.course;
}

bool compFuncByGroup(Student a, Student b)
{
    return a.group < b.group;
}

void randFillInt(int * arr, int length)
{
    for(int i{}; i < length; ++i)
    {
        arr[i] = rand();
    }
}

void randFillDouble(double * arr, int length)
{
    for(int i{}; i < length; ++i)
    {
        arr[i] = ((double)rand())/rand();
    }
}

bool compFuncDouble(double a, double b)
{
    return a < b;
}

void outputArr(Student * arr, int length, std::ostream& out)
{
    for(int i{}; i < length; ++i)
    {
        out << arr[i].course << ';' << arr[i].group << ';' << arr[i].surname << ';' << arr[i].name << ';' << arr[i].patronymic;
        for(int j{}; j < 3; ++j)
        {
            out << ';' << arr[i].marks[j];
        }
        std::cout << '\n';
    }
}
