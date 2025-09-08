#include"head.h"

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


