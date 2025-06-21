#include <iostream>

int main()
{
    // C++ 에서 문자열은 std::string 클래스로 관리됨
    std::string string_value("Hello");
    std::cout << string_value << "\n"
              << std::endl;

    string_value = "World";
    std::cout << string_value << std::endl;

    return 0;
}