#include <iostream>

class Marine
{
    int hp;               // 마린의 체력
    int coord_x, coord_y; // 마린의 위치
    int damage;           // 마린의 공격력
    bool is_dead;

public:
    Marine();
    Marine(int x, int y);

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
}

Marine::Marine(int x, int y)
{
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

void Marine::be_attacked(int damage)
{
    hp -= damage;
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
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location: (" << coord_x << ", " << coord_y << ")" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main()
{
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl
              << "마린 1이 마린 2를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();

    Marine *marines[100]; // Marine 객체를 저장하는 포인터들을 가리키는 배열

    marines[0] = new Marine(2, 3); // 객체를 동적으로 생성하면서, 자동으로 생성자를 호출해줌 new로 포인터를 반환해줌
    marines[1] = new Marine(3, 5);

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl
              << "마린 1이 마린 2를 공격! " << std::endl;
    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();
}
