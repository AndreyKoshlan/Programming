#include <windows.h>
#include <iostream>

struct IntArray {
  int *data;
  int size;
};

void checkBounds(IntArray* arr, int index) {
    if ((index >= arr->size) || (index < 0)) {
       std::cout << "Error: List index out of bounds\n";
       exit(-1);
    }
}

/** Создаёт динамический массив размера size и сохраняет его в поле data переменной arr. Поле size структуры arr становится равным параметру size */
void create(IntArray* arr, int size) {
    arr->data = new int[size]();
    arr->size = size;
}

void create(IntArray& arr, int size) {
    arr.data = new int[size]();
    arr.size = size;
}

/** Возвращает элемент массива с индексом index, при этом проверяет выход за границы массива. Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
int get(IntArray* arr, int index) {
    checkBounds(arr, index);
    return arr->data[index];
}

int get(IntArray& arr, int index) {
    checkBounds(&arr, index);
    return arr.data[index];
}

/** Изменяет значение элемента массива с индексом index на значение параметра value, при этом проверяет выход за границы массива. Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
void set(IntArray* arr, int index, int value) {
    checkBounds(arr, index);
    arr->data[index] = value;
}

void set(IntArray& arr, int index, int value) {
    checkBounds(&arr, index);
    arr.data[index] = value;
}

/** Выводит на экран содержимое массива в формате: [1, 2, 3] */
void print(IntArray* arr) {
    std::cout << "[";
    for (int i = 0; i < arr->size; i++) {
        std::cout << get(arr, i)
                  << (i < arr->size-1 ? ", " : "");
    }
    std::cout << "]\n";
}

void print(IntArray& arr) {
    std::cout << "[";
    for (int i = 0; i < arr.size; i++) {
        std::cout << get(arr, i)
                  << (i < arr.size-1 ? ", " : "");
    }
    std::cout << "]\n";
}

/** Изменяет размер массива с сохранением элементов. Если новый размер меньше, хвостовые элементы обрезаются, если больше, то дополнительные элементы инициализируются нулём */
void resize(IntArray* arr, int newSize) {
    arr->data = (int*)realloc(arr->data, sizeof(int)*newSize);
    if (arr->size < newSize) {
        memset(arr->data+arr->size,
               0,
               sizeof(int)*(newSize-arr->size));
    }
    arr->size = newSize;
}

void resize(IntArray& arr, int newSize) {
    arr.data = (int*)realloc(arr.data, sizeof(int)*newSize);
    if (arr.size < newSize) {
        memset(arr.data+arr.size,
               0,
               sizeof(int)*(newSize-arr.size));
    }
    arr.size = newSize;
}

/** Освобождает память занятую массивом. Поле data становится равным nullptr, поле size становится равным нулю. Предусмотреть случай попытки удаления уже удалённого массива */
void destroy(IntArray* arr) {
    if (arr->data != nullptr) {
        delete[] arr->data;
        arr->size = 0;
        arr->data = nullptr;
    } else {
        std::cout << "Error: Array has already been destroyed\n";
        exit(-1);
    }
}

void destroy(IntArray& arr) {
    if (arr.data != nullptr) {
        delete[] arr.data;
        arr.size = 0;
        arr.data = nullptr;
    } else {
        std::cout << "Error: Array has already been destroyed\n";
        exit(-1);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    IntArray arr = {};
    create(arr, 30);
    for (int i = 0; i < 30; i++) {
        set(arr, i, i+1);
    }
    print(arr);
    resize(arr, 50);
    print(arr);
    resize(arr, 10);
    print(arr);
    destroy(arr);
}
