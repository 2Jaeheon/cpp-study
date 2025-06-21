#include <iostream>
// using namespace std;
// 이렇게 쓰면 namespace std 안에 있는 모든 것을 사용할 수 있음

int main()
{
    int i, j;

    std::cout << "Enter num_1: ";
    std::cin >> i;

    std::cout << "Enter num_2: ";
    std::cin >> j;

    std::cout << "num_1 + num_2 = " << i + j << std::endl;
    return 0;
}