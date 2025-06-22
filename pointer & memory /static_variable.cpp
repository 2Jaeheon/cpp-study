#include <iostream>

int getNewID()
{
    static int ID = 0;
    return ++ID;
}

int main()
{
    // 정적 변수는 처음 호출될 때 한 번만 초기화되며, 초기화와 선언을 동시에 해야함.
    std::cout << getNewID() << std::endl;
    std::cout << getNewID() << std::endl;
    std::cout << getNewID() << std::endl;

    return 0;
}