#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>


struct Student
{
    std::string name;
    std::string surname;
    int course;
    std::string groupe;
    int marks[5];
};


int sumOfArr(int * arr, int n)
{
    int res{};
    for (int i = 0; i < n; ++i)
    {
        res += arr[i];
    }
    return res;
}


double averageOfArr(int * arr, int n)
{
    return 1.0*sumOfArr(arr, n) / n;
}


void sortStuds(Student * arr, int length)
{
    int i{};
    while (i != length - 1)
    {
        if (averageOfArr(arr[i].marks, 5) < averageOfArr(arr[i + 1].marks, 5))
        {
            std::swap(arr[i], arr[i+1]);
            i = 0;
        }
        else
        {
            ++i;
        }
    }
    
}


bool func_of_increase(double num1, double num2)
{
    return num1 < num2 ? 1:0;
}


bool func_of_decrease(double num1, double num2)
{
    return num1 > num2 ? 1:0;
}


void MergeTwoSortedArrs(double * res, double *arr1, double * arr2, int length1, int length2, bool (*func_of_comp)(double, double))
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
}


void mergeSort(double * res, double * subarr1, int length1, bool (*func_of_comp)(double, double), int length2 = 0, double * subarr2 = nullptr)
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
}   


void MergeSort(double *arr, int length, bool (*func_of_comp)(double, double))
{
    double* res = new double [length];
    mergeSort(res, arr, length, func_of_comp);
    delete [] res;
}


void insertSort(double * arr, int length, bool (*func_of_comp)(double, double))
{
    double * res = new double [length];
    for (int i = 1; i <= length; ++i)
    {
        MergeTwoSortedArrs(res, arr, arr + i, i, 1, func_of_comp);
    }
    delete [] res;
}


size_t returnIdxOfEdgeElem(double * arr, int length, bool (*func_of_comp)(double, double))
{
    double temp{arr[0]};
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
}


void selectionSort(double *arr, int length, bool (*func_of_comp)(double, double))
{
    for (int i = 0; i < length; ++i)
    {
        std::swap(arr[i], arr[i + returnIdxOfEdgeElem(arr + i, length - i, func_of_comp)]);
    }
}


int countDigits(double number, int accuracy)
{
    int counter{};
    number = std::abs(number);
    for (int i = 0; i <accuracy; ++i)
    {
        if ((number * pow(10, i) - static_cast<int>(number * pow(10,i))) / pow(10,i) > (pow(10, -1*accuracy)))
        {
            ++counter;
        }
    }
    return counter;
}


int compareElems(const void * elem1, const void * elem2)
{
    return countDigits(*(double*)elem2, 10) - countDigits(*(double*)elem1, 10);
}


void Qsort(double *arr, int length)
{
    qsort(arr, length, sizeof(double), compareElems);
}


void QuickSort(double * arr, int length, bool (*func_of_comp)(double, double))
{
    double pivot = arr[length / 2];
    int length1{};
    int length2{};
    int length3{};
    double * left_arr = new double [length];
    double * mid_arr = new double [length];
    double * right_arr = new double [length];
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
}


void ModBubbleSort(double * arr, int length, bool (*func_of_comp)(double, double))
{
    int i{};
    int j{length - 1};
    while (i!= length - 1 || j != 0)
    {
        if (i!= length - 1)
        {
            if (!func_of_comp(arr[i], arr[i+1]))
            {
                std::swap(arr[i], arr[i+1]);
                i = 0;
            }
            else
            {
                i += 1;
            }
        }
        if (j != 0)
        {
            if (func_of_comp(arr[j], arr[j - 1]))
            {
                std::swap(arr[j], arr[j - 1]);
                j = length - 1;
            }
            else
            {
                j -= 1;
            }
        }
    }
}


void CLInput(double *& arr, int& length)
{
    std::cout << "input count of numbers \n";
    std::cin >> length;
    while (length <= 0)
    {
        std::cout << "input positive number";
        std::cin >> length;
    }
    arr = new double [length];
    for (int i = 0; i < length; ++i)
    {
        std::cout << "input " << i+1 << "th number \n";
        std::cin >> arr[i];
    }
}


void fileInput(std::ifstream & fin, double *& arr, int & length)
{
    double * temp = new double;
    while (fin >> *temp)
    {
        ++length;
    }
    delete temp;
    fin.clear();
    fin.seekg(std::ios::beg);
    arr = new double [length];
    for(int i = 0; i < length; ++i)
    {
        fin >> arr[i];
    }
}


void output(std::ostream & out, double * arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        out << arr[i] << ' ';
    }
    std::cout << '\n';
}


void inputIntWithLimits(int & num, int left, int right)
{
    while(num < left || num > right)
    {
        std::cout << "input number between " << left << " and " << right << '\n';
        std::cin >> num;
    }
}


void inputStudentsArr(Student *& arr, int &length)
{
    std::cout << "input count of students \n";
    std::cin >> length;
    while (length <= 0)
    {
        std::cout << "input positive number";
        std::cin >> length;
    }
    arr = new Student [length];
    
    for (int i = 0; i < length; ++i)
    {
        std::cin.ignore();
        std::cout << i+1 << "th student: \n input name \n";
        getline(std::cin, arr[i].name);
        std::cout << "input sutname \n";
        getline(std::cin, arr[i].surname);
        std::cout << "input course \n";
        std::cin >> arr[i].course;
        std::cin.ignore();
        std::cout << "input groupe \n";
        getline(std::cin, arr[i].groupe);
        std::cout << "input 5 marks \n";
        std::cin >> arr[i].marks[0] >> arr[i].marks[1] >> arr[i].marks[2] >> arr[i].marks[3] >> arr[i].marks[4];
    }
}

void outputArrOfStuds(std::ostream & out, Student * arr, int length)
{
    for (int i = 0; i < length; ++i)
    {
        out << arr[i].name << ';' << arr[i].surname << ';' << arr[i].course << ';' << arr[i].groupe << ';' << arr[i].marks[0] << ' ' << arr[i].marks[1]  << ' ' << arr[i].marks[2] << ' ' << arr[i].marks[3] << ' ' << arr[i].marks[4] << '\n'; 
    }
}