#include"Point3D.h"



int main()
{
    const int SIZE{5};
    Point2D ** arr = new Point2D*[SIZE];
    int count3D{};
    int count2D{};
    for(int i{}; i < 3; ++i)
    {
        arr[i] = new Point2D();
    }
    arr[4] = new Point3D();
    for(int i{0}; i < SIZE; ++i)
    {
        if (arr[i] != nullptr)
        {
            if (dynamic_cast<Point3D*>(arr[i]) != nullptr)
            {
                ++count3D;
            }
            else
            {
                ++count2D;
            }
        }    
    }
    std::cout << count2D << ' ' << count3D;
    return 0;
}