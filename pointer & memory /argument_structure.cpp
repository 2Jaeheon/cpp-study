#include <iostream>

struct Person
{
    std::string name;
    int age;
    float height;
    float weight;
};

void check_age(Person *_adult, int _count)
{
    for (int i = 0; i < _count; i++)
    {
        if (_adult[i].age >= 21)
        {
            std::cout << "name: " << _adult[i].name << std::endl;
            std::cout << "age: " << _adult[i].age << std::endl;
            std::cout << "height: " << _adult[i].height << std::endl;
            std::cout << "weight: " << _adult[i].weight << std::endl;
        }
    }
}

int main()
{
    Person adult[3] = {
        {"John", 20, 180.5, 70.5},
        {"Jane", 21, 165.5, 50.5},
        {"Jim", 22, 170.5, 60.5}};

    check_age(adult, 3);

    return 0;
}