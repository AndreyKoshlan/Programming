#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char skipchar;
	int h1, m1, h2, m2;
	std::cout << "Введите время 1: ";
	std::cin >> h1 >> skipchar >> m1;
	std::cout << "Введите время 2: ";
	std::cin >> h2 >> skipchar >> m2;
	m1 = (h1 * 60) + m1;
	m2 = (h2 * 60) + m2;
	if (abs(m2 - m1) <= 15)
		std::cout << "Встреча состоится\n";
	else
		std::cout << "Встреча не состоится\n";
}