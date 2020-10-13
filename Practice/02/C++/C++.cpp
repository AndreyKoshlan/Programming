//02 C++

#include <iostream>
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int int_a = 3;
	int int_b = 3.14;
	double double_a = 3;
	double double_b = 3.14;
	std::cout << "(int)A = " << int_a << std::endl;
	std::cout << "(int)B = " << int_b << std::endl;
	std::cout << "(double)A = " << double_a << std::endl;
	std::cout << "(double)B = " << double_b << std::endl;
}