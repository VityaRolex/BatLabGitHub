#include <cmath>
#include <typeinfo>
#include <iostream>

void inputIntegerValue(int64_t & element)
{
    double cinTemp{};
    std::cin >> cinTemp;
    while (std::cin.fail() || cinTemp - static_cast<int32_t>(cinTemp) != 0)
 {
    if(cinTemp - static_cast<int32_t>(cinTemp) != 0)
    {
        std::cout << "it's very funny, and now enter INTEGER value \n";
    }
    if (std::cin.fail())
    {
    std::cout << "It's not funny, be more serious and try again \n";
    std::cin.clear();
    std::cin.ignore();
    }
    std::cin >> cinTemp;
  }
  element = cinTemp;
}
template<typename Type>
void BubbleSort(Type* Arr, int64_t lenght, int64_t switcher)
{
    Type temp{};
    if (switcher == 1)
    {
    for (int32_t i = 0; i < lenght; ++i)
    {
        for (int32_t j = 0; j < lenght-1; ++j)
        {
            if (Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
    }
    else
    {
        for (int32_t i = 0; i < lenght; ++i)
         {
             for (int32_t j = 0; j < lenght-1; ++j)
            {
                if (Arr[j] < Arr[j+1])
                {
                    temp = Arr[j];
                     Arr[j] = Arr[j+1];
                     Arr[j+1] = temp;
                }
            }
        }
    }

}


template<typename Type>
int32_t CountElements(Type * Arr, int64_t lenght)
{
    int32_t result{};
    int32_t index_of_first_zero{-1};
    int32_t index_of_last_zero{-1};
    for (size_t i = 0; i < lenght; ++i)
    {
        if (Arr[i] == 0 && index_of_first_zero == -1)
        {
            index_of_first_zero = i;
        }
        if (Arr[i] == 0)
        {
            index_of_last_zero = i;
        }
    }
    if (index_of_first_zero == -1)
    {
        throw "Array contains 0 zeros \n";
    }
    else if (index_of_last_zero - index_of_first_zero == 0)
    {
        throw "Array contains only 1 zero \n";
    }
    return index_of_last_zero - index_of_first_zero - 1;
}


int32_t CountElements(char * Arr, int64_t lenght)
{
    int32_t result{};
    int32_t index_of_first_zero{-1};
    int32_t index_of_last_zero{-1};
    for (size_t i = 0; i < lenght; ++i)
    {
        if (Arr[i] == '0' && index_of_first_zero == -1)
        {
            index_of_first_zero = i;
        }
        if (Arr[i] == '0')
        {
            index_of_last_zero = i;
        }
    }
    if (index_of_first_zero == -1)
    {
        throw "Array contains 0 zeros \n";
    }
    else if (index_of_last_zero - index_of_first_zero == 0)
    {
        throw "Array contains only 1 zero \n";
    }
    return index_of_last_zero - index_of_first_zero - 1;
}


template<typename Type>
int32_t FindElement(Type* arr, Type element, int64_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        if(arr[i] == element)
        {
            return i + 1;
        }
    }
    throw "Your element isn't in array";
}


template<typename Type>
void ReverseArray(Type* arr, int64_t size)
{
    int64_t lenght_of_for{size/2};
    Type tmp{};
    for(size_t i = 0; i < lenght_of_for; ++i)
    {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }

}


template<typename Type>
void PrintArray(Type* Arr, int64_t lenght)
{
    for (int32_t i = 0; i < lenght; ++i)
    {
        std::cout << Arr[i] << ' ';
    }
    std::cout << '\n';
}


template<typename Type>
void InputArr(Type* arr, int64_t size)
{
 for (int32_t i = 0; i < size; ++i)
 {
  std::cout << "Enter element number " << i + 1 << ": \n";
    std::cin >> arr[i];
    while (std::cin.fail())
    {
    std::cout << "It's not funny, be more serious and try again \n";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> arr[i];
    }
 }
}

void InputArr(int64_t* arr, int64_t size)
{
    for (int32_t i = 0; i < size; ++i)
    {
       std::cout << "Enter element number " << i + 1 << ": \n";
       inputIntegerValue(arr[i]);
    }
}


template<typename Type>
void RemoveNegativesAndFillZeros(Type* arr, int64_t size)
{
 int posIndex = 0; 
 for (int i = 0; i < size; ++i) {
  if (arr[i] >= 0) {
   arr[posIndex] = arr[i];
   posIndex++;
  }
 }
 for (int i = posIndex; i < size; ++i) {
  arr[i] = 0;
 }
}


template<typename Type>
Type FindMaxElement(Type* arr, int64_t size)
{
    Type maxElement{arr[0]};
    for (size_t i = 0; i < size; ++i) 
    {
        if (arr[i] > maxElement) 
        {
            maxElement = arr[i];
        }
    }
    return maxElement;
}


template<typename Type>
Type FindMinElement(Type* arr, int64_t size)
{
    Type minElement{arr[0]};
    for (size_t i = 0; i < size; ++i) 
    {
        if (arr[i] < minElement) 
        {
            minElement = arr[i];
        }
    }
    return minElement;
}


template<typename Type>
int64_t MaxElement(Type* arr, int64_t size)
{
 int64_t maxIndex{};
 for (int64_t i = 1; i < size; ++i)
 {
  if (arr[i] > arr[maxIndex])
  {
   maxIndex = i;
  }
 }
 return maxIndex + 1;
}


template<typename Type>
int64_t MinElement(Type* arr, int64_t size)
{
 int64_t minIndex{};
 for (int64_t i = 1; i < size; ++i)
 {
  if (arr[i] < arr[minIndex])
  {
   minIndex = i;
  }
 }
 return minIndex + 1;
}


template<typename Type>
double CalculateAverage(Type* arr, int64_t size)
{
    double result{};
    int32_t temp{};
    int64_t minIndex{MinElement(arr, size)};
    int64_t maxIndex{MaxElement(arr, size)};
    if (minIndex > maxIndex)
    {
        temp = minIndex;
        minIndex = maxIndex;
        maxIndex = temp;
    }
    if (maxIndex - minIndex == 1)
    {
        throw "Max and Min elements are neighbours, impossible to count elements between they";
    }
    for (int32_t i = minIndex; i < maxIndex-1; ++i)
    {
        result += arr[i];
    }
    return 1.0*result/(maxIndex-1-minIndex);
}


void InputSize(int64_t& size)
{
 std::cout << "Input size:\n";
 inputIntegerValue(size);
 while (size <= 0)
 {
   std::cout << "enter positive number \n";
   inputIntegerValue(size);
 }
}


bool isNumberSimple(int64_t number)
{
    if (number <= 0)
    {
        return 0;
    }
    for (size_t i = 2; i <= sqrt(number); ++i)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    if (number == 1)
    {
        return 0;
    }
    return 1;
}


int32_t outputSumOfSimpleElements(int64_t* Arr, int64_t lenght)
{
    int32_t result{};
    for (size_t i = 0; i < lenght; ++i)
    {
        if (isNumberSimple(Arr[i]))
        {
            result += Arr[i];
        }
    }
    return result;
}


template<typename Type>
void agregateAll(Type * Arr, int64_t lenght, Type &search_element)
{
    int64_t switcher_2{};
      InputArr(Arr, lenght);
      std::cout << '\n';
      std::cout << "Enter element you need to find \n";
      std::cin >> search_element;
         while (std::cin.fail())
         {
         std::cout << "It's not funny, be more serious and try again \n";
         std::cin.clear();
         std::cin.ignore();
         std::cin >> search_element;
         }
      std::cout << '\n';
      try 
      {
        int32_t temp{FindElement(Arr, search_element, lenght)};
        std::cout << "Your element is on " << temp << " position in array" << '\n';
      }
      catch (const char * error_message)
      {
        std::cout << error_message << '\n';
      }
      try
      {
        int32_t temp{CountElements(Arr, lenght)};
        std::cout << "Distance between first and last zeros is " << temp << '\n';
      }
      catch(const char * error_message)
      {
        std::cout << error_message << '\n';
      }
      if (!(typeid(search_element).name()[0] == 'c'))
      {
      std::cout << "Max element is " << FindMaxElement(Arr, lenght) << " and he is on " << MaxElement(Arr, lenght) << " position \n";
      std::cout << "Min element is " << FindMinElement(Arr, lenght) << " and he is on " << MinElement(Arr, lenght) << " position \n";
      try
      {
        double temp{CalculateAverage(Arr, lenght)};
        std::cout << "Average is " << temp << '\n';
      }
      catch(const char * error_message)
      {
        std::cout << error_message << '\n';
      }
      std::cout << "Array: \n";
      PrintArray(Arr, lenght);
      RemoveNegativesAndFillZeros(Arr, lenght);
      std::cout << "Array with removed negatives: \n";
      PrintArray(Arr, lenght);
    }
      std::cout << "Enter 1 if you want to sort array to increase and 2 for sort to decrease \n";
      
      inputIntegerValue(switcher_2);
      while (switcher_2 != 1 && switcher_2 != 2)
    {
       std::cout << "Try again \n";
       std::cin >> switcher_2;
    }
      BubbleSort(Arr, lenght, switcher_2);
      std::cout << "Sorted Array with removed negatives: \n";
      PrintArray(Arr, lenght);
      ReverseArray(Arr, lenght);
      std::cout << " Reversed sorted Array with removed negatives: \n";
      PrintArray(Arr, lenght);
}