#include <iostream>
#include <iomanip>
int main()
{
    const int n = 3;
    int mtr[n][n]{1,2,3,4,5,6,7,8,9};
    double res_mtr[n][n]{};
    int counter_of_neighbors{8};
    int flag{};
    
    for (int32_t i = 0; i < n; ++i)
    {
        for (int32_t j = 0; j < n; ++j)
        {
            std::cout << std::setw(4) << mtr[i][j] << ' ';
        }
        std::cout << '\n';

    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 || i == n - 1)
            {
                ++flag;
            }
            if (j == 0 || j == n - 1)
            {
                ++flag;
            }
            if (flag == 1)
            {
                counter_of_neighbors -= 3;
            }
            else if (flag == 2)
            {
                counter_of_neighbors -= 5;
            }
                res_mtr[i][j] = 1.0*(((j > 0 && i > 0) ? mtr[i-1][j-1] : 0) + ((i > 0) ? mtr[i-1][j] : 0) + ((i > 0 && j < n - 1) ? mtr[i-1][j+1] : 0) + ((j > 0) ? mtr[i][j-1] : 0) + ((j < n - 1) ? mtr[i][j+1] : 0) + ((i < n - 1 && j > 0) ? mtr[i+1][j-1] : 0) + ((i < n - 1)? mtr[i+1][j] : 0) + ((i < n - 1 && j < n - 1) ? mtr[i+1][j+1] : 0)) / counter_of_neighbors;
            
            counter_of_neighbors = 8;
            flag = 0;
        }
    }
    std::cout << '\n';
    for (int32_t i = 0; i < n; ++i)
    {
        for (int32_t j = 0; j < n; ++j)
        {
            std::cout << std::setw(4) << res_mtr[i][j] << ' ';
        }
        std::cout << '\n';

    }
}


