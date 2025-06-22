#include <iostream>
#include <cassert>

void print_number(int *_pt_int)
{
    // debug모드에서 _pt_int가 NULL이면 오류 메시지를 출력하고 프로그램을 종료함.e
    assert(_pt_int != NULL);
    // assert는 디버그 모드에서만 컴파일되므로 다른 코드에 영향을 주지 않는 코드로만 작성해야 함.
    std::cout << *_pt_int << std::endl;
}

int main()
{
    int a = 100;
    int *b = NULL;
    int *c = NULL;

    b = &a;
    print_number(b);

    print_number(c);

    return 0;
}