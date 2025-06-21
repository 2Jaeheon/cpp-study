#include <iostream>

int main()
{
    float float_value = 1.5f;

    double double_value = float_value; // numeric promotion
    int int_value = float_value;
    int int_value_2 = static_cast<int>(float_value);
    // static_cast는 명시적으로 형변환을 해줌

    std::cout << "float_value = " << float_value << std::endl;   // 1.5
    std::cout << "double_value = " << double_value << std::endl; // 1.5
    std::cout << "int_value = " << int_value << std::endl;       // 1
    std::cout << "int_value_2 = " << int_value_2 << std::endl;   // 1
    return 0;

    // 명시적 형변환 방법
    // 1. static_cast: 명시적 형변환
    // 2. reinterpret_cast: 메모리 주소를 변환
    // 3. dynamic_cast: 다형성 형변환 
    // 4. const_cast: const 변수를 변환

}