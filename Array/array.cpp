#include <iostream>

int main()
{

    // int nums[10] = {44, 33, 55, 3, 4, 66};

    // for (int i = 0; i < 10; i++)
    // {
    //     if (i == 5)
    //         break;
    //     std::cout << "Value at index %d " << i << std::endl;
    // }

    int twoD[5][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15},
    };

    std::cout << "Row Major Order" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << twoD[i][j] << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << "Column Major Order" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << twoD[j][i] << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}