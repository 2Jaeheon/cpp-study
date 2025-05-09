#include <iostream>
#include <string.h>

class Photon_Cannon
{
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char *cannon_name);
    Photon_Cannon(const Photon_Cannon &pc);
    ~Photon_Cannon();

    void show_status();
};

// 즉, 복사 생성자는 다른 클래스의 객체를 상수레퍼런스로 받는다는 이야기
// pc가 const이기 때문에, pc의 멤버변수들은 변경할 수 없음
// 함수 내부에서 받은 인자의 값을 변화시키는 일이 없다면 꼭 const 를 붙이는게 좋음
// Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc)
// {
//     std::cout << "복사 생성자 호출 ! " << std::endl;
//     hp = pc.hp;
//     shield = pc.shield;
//     coord_x = pc.coord_x;
//     coord_y = pc.coord_y;
//     damage = pc.damage;
// }

Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc)
{
    std::cout << "복사 생성자 호출! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y)
{
    std::cout << "생성자 호출 ! " << std::endl;
    coord_x = x;
    coord_y = y;
    hp = shield = 100;
    damage = 20;

    name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name)
{
    coord_x = x;
    coord_y = y;
    hp = shield = 100;
    damage = 20;
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon()
{
    // 0 이 아닌 값은 if 문에서 true 로 처리되므로
    // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
    // if(name != 0) 과 동일한 의미를 가질 수 있다.
    // 참고로 if 문 다음에 문장이 1 개만 온다면
    // 중괄호를 생략 가능하다.
    if (name)
        delete[] name;
}

void Photon_Cannon::show_status()
{
    std::cout << "Photon Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main()
{
    Photon_Cannon pc1(3, 3, "Cannon");
    // Compiler 는 아래의 두 문장을 동일하게 간주함.
    // Photon_Cannon pc2(pc1);
    // Photon_Cannon pc3 = pc2;
    Photon_Cannon pc2 = pc1;
    pc1.show_status();
    pc2.show_status();
}
