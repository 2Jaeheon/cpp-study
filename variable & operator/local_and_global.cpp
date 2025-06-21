#include <iostream>

int value = 0;

int main()
{

    int value = -1;

    std::cout << "value = " << value << std::endl;
    std::cout << "::value = " << ::value << std::endl;

    // 하지만 global 변수를 사용할 때는 g_ 접두사를 붙여보자
    return 0;
} 