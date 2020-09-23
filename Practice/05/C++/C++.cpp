//05 C++

#include <iostream>
#include <Windows.h>

using namespace std;

const double a = 9.8;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double x0, u0, t;
	cin >> x0 >> u0 >> t;
	cout << (x0 + u0 * t - (a * t * t) / 2);
}