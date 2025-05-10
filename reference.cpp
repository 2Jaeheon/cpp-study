#include <iostream>

class MyClass
{
    int data[5] = {10, 20, 30, 40, 50};

public:
    // 배열 원소 하나를 참조로 반환
    int &getElement(int index)
    {
        return data[index]; // 🔥 배열 요소의 별명(alias)을 반환
    }

    // 배열 전체를 참조로 반환 (배열 참조 타입: int(&)[5])
    int (&getArray())[5]
    {
        return data; // 🔥 배열 전체의 별명(alias)을 반환
    }

    void print()
    {
        for (int i = 0; i < 5; ++i)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};

int main()
{
    MyClass obj;

    // 개별 요소 수정
    obj.getElement(2) = 999;

    // 배열 전체 수정
    int(&arr)[5] = obj.getArray(); // 배열 전체에 별명 붙이기
    arr[4] = 777;

    obj.print(); // 👉 10 20 999 40 777
}