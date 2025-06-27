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
    virtual void attack_special(player target_player); // 선언만 해둬야 함.
};

void monster::attack_special(player target_player)
{
    std::cout << "기본 공격: 데미지 - 10 hp" << std::endl;
}

// 기본 몬스터 클래스 상송
class monster_a : public monster, character
{
public:
    virtual void attack_special(player target_player);
};

void monster_a::attack_special(player target_player)
{
    std::cout << "인텡글 공격: 데미지 - 15hp" << std::endl;
}

class monster_b : public monster, character
{
public:
    virtual void attack_special(player target_player);
};

void monster_b::attack_special(player target_player)
{
    std::cout << "가상 공격: 데미지 - 0hp " << std::endl;
}

class monster_c : public monster, character
{
public:
    virtual void attack_special(player target_player);
};

void monster_c::attack_special(player target_player)
{
    std::cout << "강력 뇌전 공격: 데미지 - 100hp" << std::endl;
}

int main()
{
    player player_1;

    monster mother_monster;
    monster_a forest_monster;

    mother_monster.attack_special(player_1);

    monster *mon = &forest_monster;
    std::cout << "부모 클래스로 업캐스팅 한 후 공격" << std::endl;
    mon->attack_special(player_1);

    mon = &mother_monster;
    std::cout << "부모 클래스로 업캐스팅 한 후 공격" << std::endl;
    mon->attack_special(player_1);

    return 0;
}
