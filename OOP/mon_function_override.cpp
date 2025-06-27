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
    void attack_special(player target_player);
};

void monster::attack_special(player target_player)
{
    std::cout << "기본 공격: 데미지 - 10 hp" << std::endl;
}

// 기본 몬스터 클래스 상송
class monster_a : public monster, character
{
public:
    void attack_special(player target_player);
};

void monster_a::attack_special(player target_player)
{
    std::cout << "인텡글 공격: 데미지 - 15hp" << std::endl;
}

class monster_b : public monster, character
{
public:
    void attack_special(player target_player);
};

void monster_b::attack_special(player target_player)
{
    std::cout << "가상 공격: 데미지 - 0hp " << std::endl;
}

class monster_c : public monster, character
{
public:
    void attack_special(player target_player);
};

void monster_c::attack_special(player target_player)
{
    std::cout << "강력 뇌전 공격: 데미지 - 100hp" << std::endl;
}

int main()
{
    player player_1;

    monster_a forest_monster;

    //
    monster &mon = forest_monster;
    monster_a &mon_a = forest_monster;

    std::cout << std::endl
              << "부모 클래스로 업캐스팅 후 공격" << std::endl;

    mon.attack_special(player_1);

    std::cout << std::endl
              << "자식 클래스로 공격" << std::endl;

    mon_a.attack_special(player_1);

    return 0;
}
