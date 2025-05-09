#include <string.h>
#include <iostream>
class Test
{
    char c;

public:
    Test(char _c)
    {
        c = _c;
        std::cout << "생성자 호출" << c << std::endl;
    }
    ~Test() { std::cout << "소멸자 호출" << c << std::endl; }
};
void simple_function() { Test b('b'); }
int main()
{
    Test a('a');
    simple_function();
    return 0;
}
// Test a('a');는 main() 함수에서 선언되었으므로 main() 종료 시까지 유지됩니다.
// Test b('b');는 simple_function() 함수 안에서 선언되었으므로, 이 함수가 끝나면 곧바로 소멸됩니다.

/*
생성자 호출a
생성자 호출b
소멸자 호출b
소멸자 호출a
*/