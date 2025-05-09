#include <iostream>

class Marine
{
    int hp;               // 마린의 체력
    int coord_x, coord_y; // 마린의 위치
    int damage;           // 마린의 공격력
    bool is_dead;         // 마린의 생사 여부
    char *name;           // 마린의 이름

public:
    Marine();
    Marine(int x, int y, const char *marine_name);
    Marine(int x, int y);
    ~Marine();

    int attack();                 // 공격을 하는 함수
    void be_attacked(int damage); // 공격을 받음
    void move(int x, int y);      // 새로운 위치

    void show_status(); // 상태를 보여줌
};

Marine::Marine()
{
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y)
{
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char *marine_name)
{
    // 동적으로 문자열을 할당해주고, 복사해줌
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}

void Marine::be_attacked(int damage_amt)
{
    hp -= damage_amt;
    if (hp <= 0)
    {
        is_dead = true;
    }
}

int Marine::attack()
{
    return damage;
}

void Marine::show_status()
{
    std::cout << " *** Marine *** " << name << std::endl;
    std::cout << "Location: (" << coord_x << ", " << coord_y << ")" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

// name에 생성하는 마린의 이름을 넣어줄 때, name을 동적으로 생성해서 문자열을 복사했음.
// 그러면 이렇게 동적으로 생성된 char 배열에 대한 delete를 해 주어야 함.
// 소멸될 떄 자동으로 호출되는 함수임.
Marine::~Marine()
{
    std::cout << name << " 의 소멸자 호출 ! " << std::endl;
    // name이 NULL이 아닌 경우 (즉, 동적으로 할당된 경우) delete를 통해서 해제
    if (name != NULL)
    {
        // name 자체가 char 배열이기 때문에 delete[] 를 사용해서 해제해줘야 함.
        // [] 를 꼭 사용해줘야 함.
        delete[] name;
    }
}

int main()
{
    // Marine marine1(2, 3, "Marine1");
    // Marine marine2(3, 5, "Marine2");

    // marine1.show_status();
    // marine2.show_status();

    // std::cout << std::endl
    //           << "마린 1이 마린 2를 공격! " << std::endl;
    // marine2.be_attacked(marine1.attack());

    // marine1.show_status();
    // marine2.show_status();

    Marine *marines[100]; // Marine 객체를 저장하는 포인터들을 가리키는 배열

    marines[0] = new Marine(2, 3, "Marine1"); // 객체를 동적으로 생성하면서, 자동으로 생성자를 호출해줌 new로 포인터를 반환해줌
    marines[1] = new Marine(3, 5, "Marine2");
    marines[2] = new Marine(3, 5);

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl
              << "마린 1이 마린 2를 공격! " << std::endl;
    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}
