//03 C++

#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	double double_a;
	double double_b;
	cin >> double_a >> double_b;
	int int_a = trunc(double_a);
	int int_b = trunc(double_b);
	
	printf("(int)%d %s (int)%d = ", int_a, "+", int_b);
	cout << int_a + int_b << "\n";
	printf("(int)%d %s (int)%d = ", int_a, "-", int_b);
	cout << int_a - int_b << "\n";
	printf("(int)%d %s (int)%d = ", int_a, "*", int_b);
	cout << int_a * int_b << "\n";
	printf("(int)%d %s (int)%d = ", int_a, "/", int_b);
	cout << int_a / int_b << "\n\n";

	printf("(double)%f %s (double)%f = ", double_a, "+", double_b);
	cout << double_a + double_b << "\n";
	printf("(double)%f %s (double)%f = ", double_a, "-", double_b);
	cout << double_a - double_b << "\n";
	printf("(double)%f %s (double)%f = ", double_a, "*", double_b);
	cout << double_a * double_b << "\n";
	printf("(double)%f %s (double)%f = ", double_a, "/", double_b);
	cout << double_a / double_b << "\n\n";

	printf("(int)%d %s (double)%f = ", int_a, "+", double_b);
	cout << int_a + double_b << "\n";
	printf("(int)%d %s (double)%f = ", int_a, "-", double_b);
	cout << int_a - double_b << "\n";
	printf("(int)%d %s (double)%f = ", int_a, "*", double_b);
	cout << int_a * double_b << "\n";
	printf("(int)%d %s (double)%f = ", int_a, "/", double_b);
	cout << int_a / double_b << "\n\n";

	printf("(double)%f %s (int)%d = ", double_a, "+", int_b);
	cout << double_a + int_b << "\n";
	printf("(double)%f %s (int)%d = ", double_a, "-", int_b);
	cout << double_a - int_b << "\n";
	printf("(double)%f %s (int)%d = ", double_a, "*", int_b);
	cout << double_a * int_b << "\n";
	printf("(double)%f %s (int)%d = ", double_a, "/", int_b);
	cout << double_a / int_b << "\n\n";
}