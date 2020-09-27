#include <iostream>
#include <Windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	long long n;
	std::cout << "Введите целое число: ";
	std::cin >> n;
	if (n > 0)
		std::cout << trunc(log2(n)) + 1 << std::endl;
	else
		std::cout << 0 << std::endl;
}