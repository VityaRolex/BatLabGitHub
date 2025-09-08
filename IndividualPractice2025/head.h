#ifndef FUNCS
#define FUNCS

#include <exception>
#include <chrono>
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<random>

struct Student{
    int course;
    int group;
    std::string surname;
    std::string name;
    std::string patronymic;
    int marks[3];
};


void inputLength(int& length);
void consoleInputStudent(Student * arr, int length);
std::string GetOneWordFromFile(std::ifstream& in);
void fileInputInt(int* arr, int length, std::ifstream& file);
void fileInputDouble(double* arr, int length, std::ifstream& file);
void fileInputStud(Student* arr, int length, std::ifstream& file);
void makeRandArr(int * arr, int length);
bool compFunc(int a, int b);
int countElems(std::ifstream& in);
int countStuds(std::ifstream& in);
void countSort(Student* arr, int length, Student minElem, Student maxElem);
void countSort(std::string* arr, int length, std::string minElem, std::string maxElem);
void countSort(double* arr, int length, double minElem, double maxElem);
void Data_type(int32_t& dataType);
void ChooseMethods(int32_t& Method_Sort);
bool compFunc(std::string a, std::string b);
bool EqualTwoArrs(int * arr1, int * arr2);
bool operator ==(Student a, Student b);
bool compFuncBySurname(Student a, Student b);
bool compFuncByCourse(Student a, Student b);
bool compFuncByGroup(Student a, Student b);
void randFillInt(int * arr, int length);
void randFillDouble(double * arr, int length);
bool compFuncDouble(double a, double b);
void outputArr(Student * arr, int length, std::ostream& out);




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

template<typename T>
void fileInput(T* arr, int length, std::ifstream& file)
{
    for(int i{}; i < length; ++i)
    {
        arr[i] = (GetOneWordFromFile(file)[0]);
    }
};

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
#endif