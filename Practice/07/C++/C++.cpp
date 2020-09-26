#include <iostream>
#include <Windows.h>

typedef struct COORDP {
	double X;
	double Y;
};

double* ReadLengthData() {
	std::cout << "Введите длины сторон треугольника:\n";
	double x[3];
	for (int i = 0; i <= 2; i++) {
		std::cout << "> ";
		std::cin >> x[i];
	}
	return x;
}

double* ReadCoordData() {
	std::cout << "Введите координаты точек треугольника:\n";
	double x[6];
	for (int i = 0; i <= 5; i += 2) {
		std::cout << "> ";
		std::cin >> x[i] >> x[i+1];
	}
	return x;
}

double CalcAreaByLengths(double a, double b, double c) {
	double p = (a + b + c) / 2;
	double area2 = p * (p - a) * (p - b) * (p - c);
	if (area2 < 0) {
		throw "Невозможно вычислить площадь треугольника";
	} else {
		return sqrt(area2);
	}
}

double GetLength(COORDP p1, COORDP p2) {
	return sqrt(pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2));
}

double CalcAreaByCoord(COORDP q, COORDP w, COORDP e) {
	double a = GetLength(q, w);
	double b = GetLength(w, e);
	double c = GetLength(e, q);
	return CalcAreaByLengths(a, b, c);
}

double Calculate(int way) {
	double* ptrdata;
	switch (way) {
	case 1:
		ptrdata = ReadLengthData();
		return CalcAreaByLengths(ptrdata[0], ptrdata[1], ptrdata[2]);
		break;
	case 2:
		ptrdata = ReadCoordData();
		return CalcAreaByCoord(COORDP{ ptrdata[0], ptrdata[1] },
			COORDP{ ptrdata[2], ptrdata[3] },
			COORDP{ ptrdata[4], ptrdata[5] });
	default:
		throw "Неизвестный тип ввода";
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	while (true) {
		int way;
		std::cout << "Выберите способ ввода параметров треугольника:\n\n" <<
			"1. Длины сторон\n" <<
			"2. Координаты вершин\n\n";
		std::cout << "> ";
		std::cin >> way;
		try {
			std::cout << "S = " << Calculate(way) << std::endl;
		} catch (const char* msg) {
			std::cout << msg << std::endl;
			continue;
		}
		break;
	}
}