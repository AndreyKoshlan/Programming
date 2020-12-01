#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h> 

template<typename T>
void printVector(std::vector<T> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void inputVector(std::vector<T>& v, int n) {
	v.resize(0);
	for (int i = 0; i < n; i++) {
		T element;
		std::cin >> element;
		v.push_back(element);
	}
}

template<typename T>
std::vector<std::vector<T>> make2dVector(std::vector<T> v) {
	std::vector<T> tempvec;
	std::vector<std::vector<T>> rezvec;
	for (int i = 0; i < v.size(); i++) {
		tempvec.push_back(v[i]);
		if ((i + 1) % (int)sqrt(v.size()) == 0) {
			rezvec.push_back(tempvec);
			tempvec.resize(0);
		}
	}
	return rezvec;
}

template<typename T>
bool isSorted(std::vector<T> v, bool order) {
	if (v.size() <= 1)
		return true;
	for (int i = 1; i < v.size(); i++) {
		if (order) {
			if (v[i] < v[i - 1]) return false;
		}
		else {
			if (v[i] > v[i - 1]) return false;
		}
	}
	return true;
}

//BozoSort std::vector<int>
template<typename T>
std::vector<T> BozoSort(std::vector<T> v, bool order = true) {
	srand(time(NULL));
	while (!isSorted(v, order)) {
		int r1 = rand() % v.size();
		int r2 = rand() % v.size();
		std::swap(v[r1], v[r2]);
	}
	return v;
}

//BozoSort 2d vector
template<typename T>
std::vector<T> BozoSort(std::vector<std::vector<T>> v2d, bool order = true) {
	std::vector<T> rezvect;
	for (int i = 0; i < v2d.size(); i++) {
		v2d[i] = BozoSort(v2d[i], order);
		for (int j = 0; j < v2d[i].size(); j++) {
			rezvect.push_back(v2d[i][j]);
		}
	}
	return rezvect;
}

//BozoSort 3 values
template<typename T>
std::vector<T> BozoSort(T a, T b, T c, bool order = true) {
	std::vector<T> v{ a, b, c };
	return BozoSort(v, order);
}

template<typename T>
void Output_Result(T Variable) {
	int n, i;
	std::vector<T> v;
	std::vector < std::vector<T> > v2d;
	std::cout << "Введите количество чисел: ";
	std::cin >> n;
	std::cout << "Введите массив: ";
	inputVector(v, n);
	v2d = make2dVector(v);

	std::cout << std::endl;
	std::cout << "• Отсортированный массив целых чисел: " << "\n\n";
	printVector(BozoSort(v, true));
	printVector(BozoSort(v, false));
	std::cout << "\n\n";

	std::cout << "• Отсортированный двумерный массив целых чисел: " << "\n\n";
	printVector(BozoSort(v2d, true));
	printVector(BozoSort(v2d, false));
	std::cout << "\n\n";

	std::cout << "• Отсортированные значения трех отдельных чисел: " << "\n\n";
	printVector(BozoSort(v[0], v[1], v[2], true));
	printVector(BozoSort(v[0], v[1], v[2], false));
	std::cout << "\n\n";
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "~ • ~ INT ~ • ~\n";
	
	Output_Result(1); //Число

	std::cout << "~ • ~ STRING ~ • ~\n";

	Output_Result('1'); //Буква
}