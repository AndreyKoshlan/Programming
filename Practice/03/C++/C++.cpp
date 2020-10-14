//03 C++

#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

template<typename T>
string GetVariableWithTypeString(T Var) {
	return '(' + string(typeid(T).name()) + ')' + to_string(Var);
}

template<typename T, typename U, typename V>
string GetEqualString(T a, U b, string op, V Output, bool divisionByZero = false) {
	string rez = GetVariableWithTypeString(a) + ' ' + op + ' ' + 
				 GetVariableWithTypeString(b) + " = ";
	rez += (!divisionByZero ? to_string(Output) : "Ошибка в вычислении");
	return rez;
}

template<typename T, typename U>
void Calculate(T a, U b) {
	cout << GetEqualString(a, b, "+", a + b) << endl;
	cout << GetEqualString(a, b, "-", a - b) << endl;
	cout << GetEqualString(a, b, "*", a * b) << endl;
	if ((b != 0) || (typeid(T) != typeid(int)) || (typeid(U) != typeid(int)))
		cout << GetEqualString(a, b, "/", a / b) << endl;
	else
		cout << GetEqualString(a, b, "/", 0, true) << endl;
	cout << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	double a;
	double b;
	cout << "Введите число A: ";
	cin >> a;
	cout << "Введите число B: ";
	cin >> b;

	Calculate((int)a, (int)b);
	Calculate(a, b);
	Calculate((int)a, b);
	Calculate(a, (int)b);
}