#include <iostream>
#include <exception>

// 처리되지 않은 예외 발생 시 호출될 함수
void customTerminate()
{
    std::cout << "커스텀 terminate 함수가 호출되었습니다." << std::endl;
    std::cout << "처리되지 않은 예외가 발생했습니다." << std::endl;
    abort(); // 프로그램 강제 종료
}

void throwException()
{
    throw std::runtime_error("의도적으로 발생시킨 예외");
}

int main()
{
    // 커스텀 terminate 핸들러 설정
    std::set_terminate(customTerminate);

    std::cout << "프로그램 시작" << std::endl;

    // try-catch 블록 없이 예외를 발생시킴
    throwException();

    // 이 코드는 실행되지 않음
    std::cout << "프로그램 종료" << std::endl;

    return 0;
}
