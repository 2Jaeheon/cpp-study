#include <iostream>

class bank
{
private:
    int safe;

public:
    bank();                              // 기본 생성자
    void use_counter(int _in, int _out); // 입출금 창구 함수
};

bank::bank()
{
    safe = 1000;
    std::cout << "최초 금고: " << safe << std::endl;
    std::cout << std::endl;
}

void bank::use_counter(int _in, int _out)
{
    safe += _in;
    safe -= _out;

    std::cout << "입금: " << _in << std::endl;
    std::cout << "출금: " << _out << std::endl;
    std::cout << "현재 금고: " << safe << std::endl;
    std::cout << std::endl;
}

int main()
{
    bank my_bank; // bank 인스턴스 생성

    // private에서는 접근 못함.
    // my_bank.safe = 1000; => error

    my_bank.use_counter(0, 20);
    my_bank.use_counter(50, 0);
    my_bank.use_counter(100, 50);

    return 0;
}