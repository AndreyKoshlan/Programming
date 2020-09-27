#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int x;
	std::cout << "Введите число: ";
	std::cin >> x;
	int msearch = sqrt(x);
	for (int i = 2; i <= msearch; i++) {
		if (x % i == 0) {
			std::cout << "Составное";
			return 0;
		}
	}
	std::cout << "Простое";
}