#include <iostream>
#include <Windows.h>

double Div(double x, double y) {
	if (y == 0)
		throw "Отсутствуют действительные корни";
	return x / y;
}

void CalculateLinearEq(double a, double b) {
	if ((a == 0) && (b == 0)) {
		std::cout << "Результат не определен" << "\n";
	} else {
		std::cout << "x = " << Div(-b, a) << "\n";
	}
}

void CalculateQuadraticEq(double a, double b, double c) {
	double d = b*b - 4*a*c;
	if (d < 0) {
		throw "Отсутствуют действительные корни";
	}
	double x1 = Div((-b + sqrt(d)), (2 * a));
	double x2 = Div((-b - sqrt(d)), (2 * a));
	if (x1 == x2) {
		std::cout << "x = " << x1 << "\n";
	} else {
		std::cout << "x1 = " << x1 << "\n";
		std::cout << "x2 = " << x2 << "\n";
	}
}

void Calculate(double a, double b, double c) {
	if (a == 0) {
		CalculateLinearEq(b, c);
	} else {
		CalculateQuadraticEq(a, b, c);
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	while (true) {
		double a, b, c;
		std::cout << "Введите число A: ";
		std::cin >> a;
		std::cout << "Введите число B: ";
		std::cin >> b;
		std::cout << "Введите число C: ";
		std::cin >> c;
		try {
			Calculate(a, b, c);
			break;
		}
		catch (const char* msg) {
			std::cout << msg << "\n";
		}
	}
}