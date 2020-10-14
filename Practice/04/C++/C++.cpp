//04 C++

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int orig_a, orig_b;
	cout << "Введите число A: ";
	cin >> orig_a;
	cout << "Введите число B: ";
	cin >> orig_b;
	
	//С дополнительной переменной
	{
		int a = orig_a;
		int b = orig_b;
		int c = a;
		a = b;
		b = c;
		printf("С помощью дополнительной переменной: a=%d; b=%d\n", a, b);
	}

	//Без дополнительной переменной
	{
		int a = orig_a;
		int b = orig_b;
		a = a + b;
		b = a - b;
		a = a - b;
		printf("Без помощи дополнительной переменной: a=%d; b=%d", a, b);
	}
}