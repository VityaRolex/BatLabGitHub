#include <iostream>
#include <typeinfo>
#include "functions.h"

 int main()
 {
  int64_t Arr_of_int[100]{};
  double Arr_of_double[100]{};
  char Arr_of_char[100]{};
  int64_t lenght{};
  int64_t int_element{};
  char char_element{};
  double double_element{};
  int64_t switcher{};
  std::cout << "Press 1 if you want to work with char array and 2 for work with int array and 3 for work with double array \n";
  inputIntegerValue(switcher);
  while (switcher != 1 && switcher != 2 && switcher != 3)
  {
    std::cout << "Try again \n";
    inputIntegerValue(switcher);
  }
  InputSize(lenght);
  switch(switcher)
  {
    case 1:
    {
      agregateAll(Arr_of_char, lenght, char_element);
      break;
    }
    case 2:
    {
      agregateAll(Arr_of_int, lenght, int_element);
      std::cout << "Sum of simple elements is " << outputSumOfSimpleElements(Arr_of_int, lenght) << '\n';
      break;
    }
    case 3:
    {
      agregateAll(Arr_of_double, lenght, double_element);
      break;
    }
  }
  
  return 0;
 }

