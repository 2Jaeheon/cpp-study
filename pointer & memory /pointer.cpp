#include <iostream>

int main()
{
    char char_value = 'A';
    int int_value = 123;
    double double_value = 123.456;

    char *char_pointer_value = &char_value;
    int *int_pointer_value = &int_value;
    double *double_pointer_value = &double_value;

    // 일반 변수의 데이터 출력
    std::cout << "char_value: " << char_value << std::endl;
    std::cout << "int_value: " << int_value << std::endl;
    std::cout << "double_value: " << double_value << std::endl;

    // 역참조 연산자로 포인터가 가리키는 메모리 주소에 접근해서 값을 출력
    std::cout << "char_pointer_value: " << *char_pointer_value << std::endl;
    std::cout << "int_pointer_value: " << *int_pointer_value << std::endl;
    std::cout << "double_pointer_value: " << *double_pointer_value << std::endl;

    // 역참조 연산자로 원본 데이터 덮어쓰기
    *char_pointer_value = 'Z';
    *int_pointer_value = 456;
    *double_pointer_value = 789.123;

    // 원본 데이터 출력
    std::cout << "char_value: " << char_value << std::endl;
    std::cout << "int_value: " << int_value << std::endl;
    std::cout << "double_value: " << double_value << std::endl;

    return 0;
}