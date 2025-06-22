#include <iostream>

int main()
{
    int lotto[45] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45};

    std::cout << lotto[0] << std::endl;
    std::cout << lotto[1] << std::endl;
    std::cout << lotto[2] << std::endl;
    std::cout << lotto[3] << std::endl;
    std::cout << lotto[4] << std::endl;
    std::cout << lotto[5] << std::endl;

    std::cout << "lotto + 0의 주소: " << &lotto[0] << std::endl;
    std::cout << "lotto + 1의 주소: " << &lotto[1] << std::endl;
    std::cout << "lotto + 2의 주소: " << &lotto[2] << std::endl;
    std::cout << "lotto + 3의 주소: " << &lotto[3] << std::endl;
    std::cout << "lotto + 4의 주소: " << &lotto[4] << std::endl;
    std::cout << "lotto + 5의 주소: " << &lotto[5] << std::endl;

    std::cout << "\nlotto + 0의 주소: " << lotto << std::endl;
    std::cout << "lotto + 1의 주소: " << lotto + 1 << std::endl;
    std::cout << "lotto + 2의 주소: " << lotto + 2 << std::endl;
    std::cout << "lotto + 3의 주소: " << lotto + 3 << std::endl;
    std::cout << "lotto + 4의 주소: " << lotto + 4 << std::endl;
    std::cout << "lotto + 5의 주소: " << lotto + 5 << std::endl;

    // &lotto[0] == lotto + 0
    return 0;
}