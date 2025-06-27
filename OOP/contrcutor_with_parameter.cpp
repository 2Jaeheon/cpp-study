#include <iostream>

class character
{
public:
    character() : hp(100), power(100) {};

protected:
    int hp;
    int power;
};

// character를 상속
class player : public character
{
public:
    player() {};
};

class monster
{
public:
    monster() {};
    void get_damage(int damage) {};
    void attack(player target_player) {};
    virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player)
{
    std::cout << "기본 공격: 데미지 - 10 hp" << std::endl;
}

// 기본 몬스터 클래스 상송
class monster_a : public monster, character
{
public:
    monster_a()
    {
        std::cout << "monster_a 클래스 생성자" << std::endl;
    };

    monster_a(int x, int y) : location{x, y}
    {
        std::cout << "monster_a 클래스 생성자" << std::endl;
    };

    void show_location()
    {
        std::cout << "location: " << location[0] << ", " << location[1] << std::endl;
    }

    virtual void attack_special(player target_player) override;

private:
    int location[2];
};

void monster_a::attack_special(player target_player)
{
    std::cout << "인텡글 공격: 데미지 - 15hp" << std::endl;
}

class monster_b : public monster, character
{
public:
    virtual void attack_special(player target_player) override;
};

void monster_b::attack_special(player target_player)
{
    std::cout << "가상 공격: 데미지 - 0hp " << std::endl;
}

class monster_c : public monster, character
{
public:
    virtual void attack_special(player target_player) override;
};

void monster_c::attack_special(player target_player)
{
    std::cout << "강력 뇌전 공격: 데미지 - 100hp" << std::endl;
}

int main()
{
    player player_1;
    monster_a forest_monster(10, 20);
    monster_a wood_monster;

    wood_monster.show_location();
    forest_monster.show_location();

    // forest_monster는 monster_a의 클래스의 인스턴스임.
    // 부모 클래스인 monster를 참조해도, 자신의 오버라이딩 함수가 호출되어야 함.
    // virtual 키워드를 사용해서 오버라이딩 함수를 호출할 수 있음.
    return 0;
}
