#include <iostream>

class Date
{
    int year_;
    int month_;
    int day_;

public:
    void setDate(int year, int month, int date);
    void addDay(int inc);
    void addMonth(int inc);
    void addYear(int inc);

    int getCurrentMonthTotalDays(int year, int month);

    void showDate();

    // 명시적으로 default 생성자를 만들어줌
    // 이를 통해 컴파일러가 자동으로 생성자를 만들지 않음
    Date() = default;

    Date(int year, int month, int day)
    {
        year_ = year;
        month_ = month;
        day_ = day;
    }
};

void Date::setDate(int year, int month, int date)
{
    year_ = year;
    month_ = month;
    day_ = date;
}

// 윤년 계산
int Date::getCurrentMonthTotalDays(int year, int month)
{
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month != 2)
    {
        return month_day[month - 1];
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        return 29;
    }
    else
    {
        return 28;
    }
}

void Date::addDay(int inc)
{
    while (true)
    {
        // 현재 달의 총 일수 계산
        int current_month_total_days = getCurrentMonthTotalDays(year_, month_);

        // 현재 달의 총 일수보다 증가할 일수가 작으면 증가
        if (day_ + inc <= current_month_total_days)
        {
            day_ += inc;
            break;
        }
        // 현재 달의 총 일수보다 증가할 일수가 크면 증가
        // 즉, 다음 달로 넘어가야 하는 경우
        else
        {
            inc -= (current_month_total_days - day_ + 1);
            day_ = 1;
            addMonth(1);
        }
    }
}

void Date::addMonth(int inc)
{
    addYear((inc + month_ - 1) / 12);
    month_ = month_ + inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::addYear(int inc)
{
    year_ += inc;
}

void Date::showDate()
{
    std::cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_ << "일 입니다." << std::endl;
}

class Animal
{
private:
    int food;
    int weight;

public:
    void set_animal(int _food, int _weight)
    {
        food = _food;
        weight = _weight;
    }

    void increase_food(int inc)
    {
        food += inc;
        weight += (inc / 3);
    }

    void view_stat()
    {
        std::cout << "이 동물의 food    :" << food << std::endl;
        std::cout << "이 동물의 weight  :" << weight << std::endl;
    }
};

void print(int x)
{
    std::cout << "int: " << x << std::endl;
}
// void print(char x)
// {
//     std::cout << "char: " << x << std::endl;
// }

void print(double x)
{
    std::cout << "double: " << x << std::endl;
}

int main()
{

    // 객체란 변수들과 참고자료로 이루어진 소프트웨어 덩어리

    // 객체의 인스턴스 변수는 인스턴스 메서드를 통해서만 해야함 ==> 캡슐화
    // 이를 하는 이유는 객체의 내부 동작을 몰라도 사용할 수 있기 때문임.

    Animal animal;
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();

    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);

    // 오버로딩 하는 과정
    // 1. 자신과 타입이 일치하는 함수를 찾는다.
    // 2. 자신과 일치하는 타입이 없는 경우에는 형변환을 통해 일치하는 함수를 찾아본다.
    // char, unsigned char, short int는 int로 형변환 된다.
    // float은 double로 형변환 된다.
    // 3. 일치하는 것이 없다면 더 포괄적인 형변환을 통해 일치하는 함수를 찾음.
    // numeric 타입은 다른 숫자 타입으로 변환
    // Enum 도 임의의 숫자 타입으로 변환
    // 4. 정의된 타입 변환으로 일치하는 것을 찾는다.
    // 위 과정을 통해서도 일치하는 것이 없다면 ambiguous 라고 판단해 오류 발생

    Date day(2011, 3, 1);
    Date day2; // 기본생성자를 정의하라고 명시적으로 알려줬기 때문에 오류 발생
    day2.setDate(2011, 3, 1);
    day.showDate();

    day.addDay(30);
    day.showDate();

    day.addDay(2000);
    day.showDate();

    day.setDate(2012, 1, 31);
    day.addDay(29);
    day.showDate();

    day.setDate(2012, 8, 4);
    day.addDay(2500);
    day.showDate();

    return 0;
}