#include <iostream>

void func_throw()
{
    std::cout << std::endl;
    std::cout << "func_throw() 함수 내부" << std::endl;
    std::cout << "throw -1" << std::endl;

    throw -1;
    std::cout << "after throw -1" << std::endl;
}

void func_2()
{
    std::cout << std::endl;
    std::cout << "func_2() 함수 내부" << std::endl;
    std::cout << "func_throw() 호출" << std::endl;

    func_throw();
    std::cout << "after func_throw()" << std::endl;
}

void func_1()
{
    std::cout << std::endl;
    std::cout << "func_1() 함수 내부" << std::endl;
    std::cout << "func_2() 호출" << std::endl;

    func_2();
    std::cout << "after func_2()" << std::endl;
}

int main()
{
    std::cout << "main() 함수 내부" << std::endl;
    try
    {
        std::cout << "func_1() 호출" << std::endl;
        func_1();
    }

    catch (int exec)
    {
        std::cout << std::endl;
        std::cout << "catch " << exec << std::endl;
    }

    return 0;
    // main -> func_1 -> func_2 -> func_throw
    // 예외가 계속해서 전달됨
}