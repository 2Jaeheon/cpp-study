#include <iostream>

void func_throw()
{
    std::cout << "func_throw" << std::endl;
    std::cout << "throw -1" << std::endl;
    throw -1;
    std::cout << "after throw -1" << std::endl;
}

int main()
{
    try
    {
        func_throw();
    }

    catch (int exec)
    {
        std::cout << "catch " << exec << std::endl;
    }

    return 0;
    //func_throw에서 던진 예외가 이 함수를 호출한 main 영역의 catch에서 정상으로 처리된 것을 확인할 수 있음.
    // 즉, 예외 처리의 책임은 throw가 발생한 함수를 호출한 쪽으로 넘어감.
    // 함수를 호출한 쪽으로 전달되는 현상을 stack unwinding이라고 함.
}