#include <iostream>


typedef struct Bird {
  char name[30];
  int age;

  int health;
  int food;
  int clean;
  int height;
} Animal;

void create_animal(Animal *animal) {
  std::cout << "Enter Animal Name: ";
  std::cin >> animal->name;

  std::cout << "Enter Animal Age: ";
  std::cin >> animal->age;

  animal->health = 100;
  animal->food = 100;
  animal->clean = 100;
}


void play(Animal *animal) {
  animal->health += 10;
  animal->food -= 20;
  animal->clean -= 30;
}

void one_day_pass(Animal *animal) {
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}

void show_stat(Animal *animal) {
  std::cout << animal->name << "의 상태" << std::endl;
  std::cout << "체력: " << animal->health << std::endl;
  std::cout << "배부름: " << animal->food << std::endl;
  std::cout << "청결: " << animal->clean << std::endl;
}


int main() {
  // 컴파일러에 의해서 어느정도 안정성이 보장되는 스택과는 다르게 힙은 사용자가 스스로 제어해야해서 책임이 따른다.
  // C에서는 malloc/free를 사용해서 메모리를 할당하고 해제하는데, C++에서는 new/delete를 사용한다.

  /*
  int *p = new int;
  *p = 10;

  std::cout << *p << std::endl;

  delete p;
  */

  /*// new로 배열 할당하기
  int arr_size;
  std::cout << "array size: ";
  std::cin >> arr_size;
  int *list = new int[arr_size];

  for (int i = 0; i < arr_size; i++) {
    std::cin >> list[i];
  }

  for (int i = 0; i < arr_size; i++) {
    std::cout << i << "th element of list: " << list[i] << std::endl;
  }
  delete[] list; // 배열을 해제할 때는 delete[]를 사용해야 한다.*/

  Animal *list[10];
  int animal_num = 0;

  for (;;) {
    std::cout << "1. 동물 추가하기" << std::endl;
    std::cout << "2. 놀기" << std::endl;
    std::cout << "3. 상태 보기" << std::endl;
    std::cout << "0. 종료하기" << std::endl;
    int input;
    std::cin >> input;

    switch (input) {
        int play_with;

      case 0:
        return 0;

      case 1:
        list[animal_num] = new Animal;
        create_animal(list[animal_num]);

        animal_num++;
        break;

      case 2:
        std::cout << "누구랑 놀게? ";
        std::cin >> play_with;
        if (play_with < animal_num) {
          play(list[play_with]);
        }
        break;

      case 3:
        std::cout << "누구껄 보게? ";
        std::cin >> play_with;
        if (play_with < animal_num) {
          show_stat(list[play_with]);
        }
        break;
    }
    for (int i = 0; i != animal_num; i++) {
      one_day_pass(list[i]);
    }
  }

  for (int i = 0; i != animal_num; i++) {
    delete list[i];
  }
}
