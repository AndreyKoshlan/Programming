#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	double x, value;
	int y;
	std::cout << "Введите число возводимое в степень: ";
	std::cin >> x;
	std::cout << "Введите степень: ";
	std::cin >> y;
	if (y < 0) {
		x = 1 / x;
		y = -y;
	}
	value = 1;
	for (int i = 0; i < y; i++) {
		value *= x;
	}
	std::cout << value;
}