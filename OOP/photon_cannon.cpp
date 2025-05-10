// 복사 생성자 실습
// 복사 생성자: 이미 생성된 객체를 이용해 새로운 객체를 초기화할 때 호출되는 생성자
// ClassName(const ClassName &other);
// reference를 통해서 효율을 높임

/*
얕은 복사 (Shallow Copy)
    •	객체의 포인터만 복사합니다.
    •	두 객체가 같은 메모리 공간을 공유하게 됩니다.
    •	문제가 되는 이유: 두 객체 중 하나가 소멸되면 다른 객체의 포인터도 무효화됩니다.
    → 더블 삭제(double delete) 오류 발생 가능!

깊은 복사 (Deep Copy)
    •	객체의 실제 메모리 공간까지 복사합니다.
    •	원본 객체와 복사된 객체는 독립된 메모리를 가집니다.
    •	안정적이고 안전한 메모리 사용이 가능!


즉, 복사생성자에서 name을 그대로 복사하는 것이 아닌, 새로운 메모리를 할당하고 그 메모리에 값을 복사해야 함
*/
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

// 만약 이렇게 선언해서 만들지 않는다면,
// 기본적으로 컴파일러가 default 복사 생성자를 만들어줌
// 이 복사 생성자는 얕은 복사를 수행함
// 즉, 멤버 변수들을 그대로 복사함
// 이 경우, 두 객체가 같은 메모리 공간을 공유하게 됨
// 둘 중 하나가 소멸되면 다른 객체의 포인터도 무효화됨
// 더블 삭제(double delete) 오류 발생 가능!
Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc)
{
    std::cout << "복사 생성자 호출! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    // 깊은 복사
    // 이를 사용하지 않으면, 두 객체가 같은 메모리 공간을 공유하게 됨
    // 둘 중 하나가 소멸되면 다른 객체의 포인터도 무효화됨
    // 더블 삭제(double delete) 오류 발생 가능!
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
