#include <iostream>

// noexcept 사용 예제
void 안전한_더하기(int a, int b) noexcept
{
    std::cout << a << " + " << b << " = " << a + b << std::endl;
}

void 위험한_나누기(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error("0으로 나눌 수 없습니다!");
    }
    std::cout << a << " / " << b << " = " << a / b << std::endl;
}

int main()
{
    // 1. 안전한 함수 호출 (예외가 절대 발생하지 않음)
    std::cout << "안전한 더하기 함수 실행:" << std::endl;
    안전한_더하기(10, 20);

    // 2. 위험한 함수 호출 (예외가 발생할 수 있음)
    std::cout << "\n위험한 나누기 함수 실행:" << std::endl;
    try
    {
        위험한_나누기(10, 2); // 정상 실행
        위험한_나누기(10, 0); // 예외 발생!
    }
    catch (const std::exception &e)
    {
        std::cout << "에러 발생: " << e.what() << std::endl;
    }

    return 0;
}
