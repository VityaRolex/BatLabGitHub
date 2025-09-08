#include <chrono>
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<random>
#include"head.h"

template<typename T>
void outputArr(T* arr, int length, std::ostream& out)
{
    for(int i{}; i < length; ++i)
    {
        out << arr[i] << '\n';
    }
};


template<typename T>
void shakeSort(T * arr, int length, bool (*compFunc)(T, T))
{
    bool flag{};
    int counter{};
    while(!flag)
    {
        flag = 1;
        counter = 0;
        while(counter < length - 1)
        {
            if(!compFunc(arr[counter],arr[counter+1]))
            {
                std::swap(arr[counter],arr[counter+1]);
                flag = false;   
            }
            ++counter;
        }
        while(counter > 1)
        {
            if(compFunc(arr[counter], arr[counter - 1]))
            {
                std::swap(arr[counter],arr[counter-1]);
                flag = false;
            }
            --counter;
        }
    }
};


template<typename T>
void combSort(T * arr, int length, bool (*compFunc)(T, T))
{
    
    for (int step{length - 1}; step > 0; --step)
    {
        for (int i{}; i < length - step; ++i)
        {
            if(!compFunc(arr[i], arr[i+step]))
            {
                std::swap(arr[i], arr[i + step]);
            }
        }
    }
};


template<typename T>
void countSort(T * arr, int length, int left_lim, int right_lim)
{
    int count_length{right_lim - left_lim + 1};
    int count_arr[count_length]{};
    int independent_counter{};
    for (int i{}; i < length; ++i)
    {
        ++count_arr[arr[i] - left_lim];
    }
    for(int i{}; i < count_length; ++i)
    {
        while(count_arr[i] != 0)
        {
            arr[independent_counter] = i + left_lim;
            --count_arr[i];
            ++independent_counter;
        }
    }
};

template<typename T>
void MergeTwoSortedArrs(T * res, T *arr1, T * arr2, int length1, int length2, bool (*func_of_comp)(T, T))
{
    int k{};
    int j{};
    int i{};
    while (i < length1 && j < length2)
    {
        if(func_of_comp(arr1[i],arr2[j]))
        {
            res[k++] = arr1[i++];
        }
        else 
        {
            res[k++] = arr2[j++];
        }
    }
    if (i != length1)
    {
        for (; i < length1;)
        {
            res[k++] = arr1[i++];
        }
    }
    if (j != length2)
    {
        for (; j < length2;)
        {
            res[k++] = arr2[j++];
        }
    }
    for (int i = 0; i < length1 + length2; ++i)
    {
        arr1[i] = res[i];
    }
};

template<typename T>
void mergeSort(T * res, T * subarr1, int length1, bool (*func_of_comp)(T, T), int length2 = 0, T * subarr2 = nullptr)
{
    if(length1 != 1 && length2 != 1)
    {
        
        mergeSort(res, subarr1, length1/2, func_of_comp, length1 - length1/2, subarr1 + length1/2);
        if (length2 != 0)
        {
            mergeSort(res, subarr2,length2/2, func_of_comp, length2 - length2/2, subarr2 + length2/2);
        }
    }
    if (length1 == 2)
        {
            if (!func_of_comp(subarr1[0], subarr1[1]))
            {
                std::swap(subarr1[0], subarr1[1]);
            }
        }
        if (length2 == 2)
        {
        if (!func_of_comp(subarr2[0], subarr2[1]))
            {
                std::swap(subarr2[0], subarr2[1]);
            }
        }
    MergeTwoSortedArrs(res, subarr1, subarr2, length1, length2, func_of_comp);
    return;
};

template<typename T>
void MergeSort(T *arr, int length, bool (*func_of_comp)(T, T))
{
    T* res = new T [length];
    mergeSort(res, arr, length, func_of_comp);
    delete [] res;
};

template<typename T>
void insertSort(T * arr, int length, bool (*func_of_comp)(T, T))
{
    T * res = new T [length];
    for (int i = 1; i <= length; ++i)
    {
        MergeTwoSortedArrs(res, arr, arr + i, i, 1, func_of_comp);
    }
    delete [] res;
};

template<typename T>
size_t returnIdxOfEdgeElem(T * arr, int length, bool (*func_of_comp)(T, T))
{
    T temp{arr[0]};
    size_t idx{};
    for (int i = 0; i < length; ++i)
    {
        if (func_of_comp(arr[i], temp))
        {
            idx = i;
            temp = arr[i];
        }
    }
    return idx;
};

template<typename T>
void selectionSort(T *arr, int length, bool (*func_of_comp)(T, T))
{
    for (int i = 0; i < length; ++i)
    {
        std::swap(arr[i], arr[i + returnIdxOfEdgeElem(arr + i, length - i, func_of_comp)]);
        outputArr(arr, length, std::cout);
        std::cout << '\n';
    }
};


template<typename T>
void QuickSort(T * arr, int length, bool (*func_of_comp)(T, T))
{
    T pivot = arr[length / 2];
    int length1{};
    int length2{};
    int length3{};
    T * left_arr = new T [length];
    T * mid_arr = new T [length];
    T * right_arr = new T [length];
    for (int i = 0; i < length; ++i)
    {
        if (func_of_comp(arr[i], pivot))
        {
            left_arr[length1] = arr[i];
            ++length1;
        }
        else if (arr[i] == pivot)
        {
            mid_arr[length2] = arr[i];
            ++length2;
        }
        else
        {
            right_arr[length3] = arr[i];
            ++length3;
        }
    }
    if (length1 > 1)
    {
        QuickSort(left_arr, length1, func_of_comp);
    }
    if (length3 > 1)
    {
        QuickSort(right_arr, length3, func_of_comp);
    }
    int i = 0;
    for (int j = 0; j < length1; ++j)
    {
        arr[i] = left_arr[j];
        ++i;
    }
    for (int j = 0; j < length2; ++j)
    {
       arr[i] = mid_arr[j];
        ++i;
    }
    for (int j = 0; j < length3; ++j)
    {
        arr[i] = right_arr[j];
        ++i;
    }
};


template<typename T>
void ModBubbleSort(T * arr, int length, bool (*func_of_comp)(T, T))
{
    int i{};
    int j{length - 1};
    while (i!= length - 1)
    {
        if (i!= length - 1)
        {
            if (func_of_comp(arr[i + 1], arr[i]))
            {
                std::swap(arr[i], arr[i+1]);
                i = 0;
            }
            else
            {
                i += 1;
            }
        }
    }
}

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

template<typename T>
void consoleInput(T * arr, int length)
{
    for (int i{}; i < length; ++i)
    {
        std::cout << i+1 << ")";
        std::cin >> arr[i];
        std::cout << '\n';
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


template <typename T>
void fisherYatesShuffle(T* arr, int length) {
    std::random_device rd;     
    std::mt19937 gen(rd());    
    for (int i = length - 1; i > 0; --i) {
        std::uniform_int_distribution<> dist(0, i);
        int j = dist(gen);
        std::swap(arr[i], arr[j]);
    }
}
template<typename T>
bool orderCheck(T* arr, int length, bool (*compareFunc)(T, T))
{
    for (int i{}; i < length - 1; ++i)
    {
        if (!compareFunc(arr[i], arr[i+1]))
        {
            return 0;
        }
    }
    return 1;
}


template<typename T>
void bogoSort(T* arr, int length, bool (*compFunc)(T,T))
{
    while(!orderCheck(arr, length, compFunc))
    {
        fisherYatesShuffle(arr, length);
        outputArr(arr, length, std::cout);
        std::cout << '\n';
    }
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


template<typename T>
void fileInput(T* arr, int length, std::ifstream& file)
{
    for(int i{}; i < length; ++i)
    {
        arr[i] = (GetOneWordFromFile(file)[0]);
    }
};


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


template<typename T>
T maxElem(T * arr, int length, bool (*compFunc)(T, T))
{
    T res = arr[0];
    for (int i{}; i < length; ++i)
    {
        if (!compFunc(res, arr[i]))
        {
            res = arr[i];
        }
    }
    return res;
}

template<typename T>
T minElem(T * arr, int length, bool (*compFunc)(T, T))
{
    T res = arr[0];
    for (int i{}; i < length; ++i)
    {
        if (compFunc(res, arr[i]))
        {
            res = arr[i];
        }
    }
    return res;
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

template<typename T>
void Sorting(T* arr, int32_t size, int32_t Method_Sort, bool (*compFunc)(T,T))
{
    switch (Method_Sort)
    {
    case 0:
        ModBubbleSort(arr, size, compFunc);
        break;
    case 1:
        shakeSort(arr, size, compFunc);
        break;
    case 2:
        combSort(arr, size, compFunc);
        break;
    case 3:
        insertSort(arr, size, compFunc);
        break;
    case 4:
        selectionSort(arr, size, compFunc);
        break;
    case 5:
        QuickSort(arr, size, compFunc);
        break;
    case 6:
        MergeSort(arr, size, compFunc);
        break;
    case 7:
        countSort(arr, size, minElem(arr, size, compFunc), maxElem(arr, size, compFunc));
    case 8:
        bogoSort(arr, size, compFunc);
        break;
    default:
        std::cout << "This sort method is not realized.\n";
        break;
    }
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


int main()
{
    std::ifstream file("file.txt");
    int inputType;
    int length;
    int dataType;
    int * arr0{};
    std::string * arr1{};
    Student * arr2{};
    double * arr4{};

    try
    {
        
        std::cout << "Choose input type: 1 - from file, 2 - from console, 3 - random fill\n";
        std::cin >> inputType;
        if(inputType > 3 || inputType < 1)
        {
            throw std::invalid_argument("invalid input type");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }


    try
    {
        
        std::cout << "Select data type: 0 - integer numbers, 1 - strings, 2 - students, 3 - float numbers\n";
        std::cin >> dataType;
        if (dataType > 3 || dataType < 0)
        {
            throw std::invalid_argument("That type doesn't exist");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 3;
    }

    if(inputType == 1)
    {
        switch (dataType)
        {
        case 0:
        {
            length = countElems(file);
            arr0 = new int[length];
            fileInput(arr0, length, file);
            break;
        }
            
        case 1:
        {
            length = countElems(file);
            arr1 = new std::string[length];
            fileInput(arr1, length, file);
            break;
        }
            
        case 2:
        {
            length = countStuds(file);
            arr2 = new Student[length];
            fileInputStud(arr2,length, file);
            break;
        }    
        case 3:
        {
            length = countStuds(file);
            arr4 = new double[length];
            fileInputDouble(arr4, length, file);
            break;
        }
        default:
            break;
        }
    }
    
    if (inputType == 2)
    {
        try
        {
            std::cout << "input length of array\n";
            std::cin >> length;
            if (length <= 0)
            {
                throw std::length_error("invalid length of array");
            }  
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 2;
        }
        switch (dataType)
        {
        case 0:
        {
            arr0 = new int[length];
            consoleInput(arr0, length);
            break;
        }
        case 1:
        {
            arr1 = new std::string[length];
            consoleInput(arr1, length);
            break;
        }
        case 2:
        {
            arr2 = new Student[length];
            consoleInputStudent(arr2, length);
            break;
        }
        case 3:
        {
            arr4 = new double[length];
            consoleInput(arr4, length);
            break;
        }
        default:
            break;
        }
    }

    if(inputType == 3)
    {
        std::cout << "input length\n";
        std::cin >> length;
        if (length <= 0)
        {
            throw std::length_error("length must be positive number");
        }
        switch (dataType)
        {
        case 0:
        {
            arr0 = new int[length];
            randFillInt(arr0, length);
            break;
        }
        case 3:
        {
            arr4 = new double[length];
            randFillDouble(arr4, length);
            break;
        }
        default:
        {
            std::cout << "There is no random generator for your type\n";
            return 5;
        }
        }
    }

    int sortType;
    ChooseMethods(sortType);
    switch (dataType)
    {
    case 0:
    {
        Sorting(arr0, length, sortType, compFunc);
        break;
    }
    case 1:
    {
        Sorting(arr1, length, sortType, compFunc);
        break;
    }
    case 2:
    {
        Sorting(arr2, length, sortType, compFuncByCourse);
        for (int i{}; i < length; ++i)
        {
            for(int j{i}; j < length; ++j)
            {
                if (arr2[j + 1].course != arr2[i].course)
                {
                    Sorting(&arr2[i], j - i + 1, sortType, compFuncByGroup);
                }
            }
        }
        for (int i{}; i < length; ++i)
        {
            for(int j{i}; j < length; ++j)
            {
                if (arr2[j + 1].course != arr2[i].course || arr2[j+1].group != arr2[i].group)
                {
                    Sorting(&arr2[i], j - i + 1, sortType, compFuncBySurname);
                }
            }
        }
        
        break;
    }
    case 3:
    {
        Sorting(arr4, length, sortType, compFuncDouble);
        break;
    }
    default:
        break;
    }

    int returnType;
    try
    {
        
        std::cout << "Choose output type: 1 - to file, 2 - to console\n";
        std::cin >> returnType;
        if(returnType > 2 || returnType < 1)
        {
            throw std::invalid_argument("invalid output type");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 4;
    }
    std::ofstream out("out.txt");
    switch(returnType)
    {
        case 1:
        {
            switch(dataType)
            {
                case 2:
                {
                    outputArr(arr2, length, out);
                    break;
                }
                case 0:
                {
                    outputArr(arr0, length, out);
                    break;
                }
                case 1:
                {
                    outputArr(arr1, length, out);
                    break;
                }
                case 3:
                {
                    outputArr(arr4, length, std::cout);
                    break;
                }
                default:
                    break;

            }
        }
        case 2:
        {
            switch(dataType)
            {
                case 2:
                {
                    outputArr(arr2, length, std::cout);
                    break;
                }
                case 0:
                {
                    outputArr(arr0, length, std::cout);
                    break;
                }
                case 1:
                {
                    outputArr(arr1, length, std::cout);
                    break;
                }
                case 3:
                {
                    outputArr(arr4, length, std::cout);
                    break;
                }
                default:
                    break;

            }
        }
    }
    
  



    


    


    auto start_time = std::chrono::system_clock::now();


    auto finish_time = std::chrono::system_clock::now();
   
    auto elapsed_milliseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time);
    std::cout << "time:" << elapsed_milliseconds.count() << '\n';

    return 0;
}


