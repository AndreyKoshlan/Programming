#include <windows.h>
#include <iostream>
#include <algorithm>

void create(int **arr, size_t length, int begin = 0, int step = 0) {
    *arr = new int[length];
    begin -= step;
    std::generate(&(*arr)[0],  &(*arr)[length], [&begin, step] {return begin+=step;});
}

void destroy(int **arr) {
    if (*arr != nullptr) {
        delete[] *arr;
        *arr = nullptr;
    }
}

int* sort(int* arr, size_t length) {
    for (size_t p1 = 1; p1 < length; p1++) {
        size_t p2 = p1;
        while ((p2 > 0) & (arr[p2] <= arr[p2-1])) {
            std::swap(arr[p2], arr[p2-1]);
            p2--;
        }
    }
    return arr;
}

void print(int* arr, size_t length) {
    for (size_t i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    size_t length; size_t begin; int step;
    std::cout << "Введите: длину массива, начальный член и шаг арифметической прогрессии\n>";
    std::cin >> length >> begin >> step;
    int *arr = {0};
    create(&arr, length, begin, step);
    sort(arr, length);
    print(arr, length);
    destroy(&arr);
}
