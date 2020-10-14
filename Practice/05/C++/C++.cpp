//05 C++

#include <iostream>
#include <Windows.h>

using namespace std;

const double a = 9.8;

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	cout << "Введите параметры x₀, u₀, t: \n> ";
	double x0, u0, t;
	cin >> x0 >> u0 >> t;
	cout << "S = " <<abs(u0 * t - (a * t * t) / 2);
}