#include <iostream>

// 배열로 받으면 배열의 첫 주소가 전달되므로 배열의 크기를 따로 받아야 함
int average(int _arr[], int _count)
{
    int sum = 0;

    for (int i = 0; i < _count; i++)
    {
        sum += _arr[i];
    }

    return sum / _count;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int result = average(arr, 5);

    std::cout << "평균: " << result << std::endl;

    return 0;
}