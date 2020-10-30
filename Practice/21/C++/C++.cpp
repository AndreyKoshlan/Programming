#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

#define _weights vector<weight_type>

struct weight_type {
	string Name;
	double Max;
};

const _weights weights = { 
	weight_type{"Underweight", 18.5},
	weight_type{"Normal", 25.0},
	weight_type{"Overweight", 30.0},
	weight_type{"Obesity", INFINITY}
};

double BMI(double weight, double height) {
	return weight / pow(height, 2);
}

void printBMI(double BMI) {
	for (int i = 0; i < weights.size(); i++) {
		if (BMI < weights[i].Max) {
			cout << weights[i].Name;
			break;
		}
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	double weight, height;
	cout << "Введите вес и рост: ";
	cin >> weight >> height;
	printBMI(BMI(weight, height / 100.0));
}