#include"mystring.h"
#include <cstring>

int main()
{
    try
    {
        String a("aboba");
        String b("boba");
        std::cout << (a <= b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}