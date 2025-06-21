#include <iostream>

const long double km_per_mile = 1.609344L;

// operator를 사용해서 직접 리터럴을 정의하는 것. 사용자 정의 리터럴 연산자임.

long double operator"" _km(long double value)
{
    return value;
}

long double operator"" _mi(long double value)
{
    return value * km_per_mile;
}

int main()
{
    long double distance_1 = 1.0_km; // km는 그대로 저장
    long double distance_2 = 1.0_mi; // mile은 km단위로 변환해서 저장

    std::cout << distance_1 + distance_2 << std::endl;

    return 0;
}