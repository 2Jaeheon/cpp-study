#include <iostream>
#include <string>

using namespace std;

template <typename T> // 템플릿 선언
T data_sum(T operand1, T operand2)
{ // 함수 템플릿 정의
    return operand1 + operand2;
}

int main()
{
    int data1 = 3, data2 = 5;
    double data3 = 4.5, data4 = 8.9;
    string data5 = "Hello", data6 = "World";

    cout << data_sum(data1, data2) << endl;
    cout << data_sum(data3, data4) << endl;
    cout << data_sum(data5, data6) << endl;

    return 0;
}