#include <iostream>

int main()
{
    int *pt_int_value = new int;
    int *pt_int_array = new int[10];

    *pt_int_value = 100;
    std::cout << *pt_int_value << std::endl;

    for (int i = 0; i < 10; i++)
    {
        pt_int_array[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << pt_int_array[i] << std::endl;
    }

    delete pt_int_value;
    delete[] pt_int_array;

    return 0;
}