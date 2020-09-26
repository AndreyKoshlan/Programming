#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	double a, b;
	char op;
	while (true) {
		std::cin >> a >> op >> b;
		switch (op) {
		case '+':
			std::cout << a + b;
			break;
		case '-':
			std::cout << a - b;
			break;
		case '*':
			std::cout << a * b;
			break;
		case '/':
			if (b == 0) {
				std::cout << "Деление на \"0\" невозможно\n";
				continue;
			} else
				std::cout << a / b;
		}
		break;
	}
}