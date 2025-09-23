#include"mystring.h"
#include <cstring>

int main()
{
    try
    {
        Mystring a("aboba");
        Mystring b("boba");
        std::cout << (a <= b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}