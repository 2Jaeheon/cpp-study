#include <iostream>

void swap(int &ref_a, int &ref_b)
{
    int temp = ref_a;
    ref_a = ref_b;
    ref_b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    swap(a, b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;

    // 레퍼런스는 기존 변수의 alias (별칭)
    // 레퍼런스 변수는 선언 후 반드시 참조할 변수를 지정해야 함.
    // 참조할 대상이 지정된 레퍼런스 변수는 다른 변수를 참조하도록 변경할 수 없음.
    // 레퍼런스 변수는 상수를 참조할 수 없음.
}