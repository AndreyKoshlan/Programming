#include <iostream>
#include <Windows.h>

const
	int VARIABLE_LIMIT = 20;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int f;
	long long value = 1;
	while (true) {
		std::cout << "Введите факториал: ";
		std::cin >> f;
		if (f > VARIABLE_LIMIT) {
			std::cout << "Переполнение" << std::endl;
			continue;
		}
		for (int i = 1; i <= f; i++) {
			value *= i;
		}
		std::cout << value << std::endl;
		break;
	}
}