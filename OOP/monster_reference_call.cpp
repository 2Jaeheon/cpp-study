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
    virtual void attack_special(player target_player) override;
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
    monster_a forest_monster;

    monster &mon = forest_monster;     // 부모 클래스에 대입
    monster_a &mon_a = forest_monster; // 자식 클래스에 대입

    // 가상함수로 인해서 부모를 참조하였으나, 자식의 오버라이딩 함수가 호출됨.
    std::cout << "부모 클래스 레퍼런스로 공격" << std::endl;
    mon.attack_special(player_1);

    std::cout << "자식 클래스 레퍼런스로 공격" << std::endl;
    mon_a.attack_special(player_1);

    std::cout << "네임스페이스 활용 공격" << std::endl;
    mon_a.monster::attack_special(player_1);

    // forest_monster는 monster_a의 클래스의 인스턴스임.
    // 부모 클래스인 monster를 참조해도, 자신의 오버라이딩 함수가 호출되어야 함.
    // virtual 키워드를 사용해서 오버라이딩 함수를 호출할 수 있음.
    return 0;
}
