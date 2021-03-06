﻿/*

1.

	При одинаковой длине вектора, каждый последующий адрес элемента вектора отличается
	на 4 байта (размерность int). Если выделенной памяти для вектора достаточно для
	добавления нового элемента, то все адреса чисел int сохраняются, а новый элемент смещается на 4 байта
	от предыдущего. Если выделенной памяти недостаточно, то выделяется новая память для вектора.
	Все значения старого копируются в новую выделенную область, при этом изменяются адреса значений вектора.

2.

	В зависимости от значения vector::capacity(). Если выделенной памяти недостаточно для добавления 25-го элемента,
	приложение выделит новую виртуальную память для данных вектора и значение 15-го элемента не изменится.

3.

	При использовании метода pop_back приложение уменьшает размер вектора на единицу.
	Адреса чисел остаются неизменными, так как нет необходимости для выделения нового региона памяти.

4.

	Результаты отличаются, так как во втором случае передается копия вектора, для которого конструктор выделит
	новый регион памяти.

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

//#define ПО_ССЫЛКЕ
#define ПО_ЗНАЧЕНИЮ

using std::vector;
using std::ostream;

#ifdef ПО_ССЫЛКЕ
ostream& operator<<(ostream& os, const vector<int>& x) {
	os << x.size() << "\t| ";
	for (int i = 0; i < x.size(); i++) {
		os << &x[i];
		if (i + 1 < x.size())
			os << " ";
	}
	os << std::endl;
	return os;
}
#endif
#ifdef ПО_ЗНАЧЕНИЮ
ostream& operator<<(ostream& os, vector<int> x) {
	os << x.size() << "\t| ";
	for (int i = 0; i < x.size(); i++) {
		os << &(x[i]);
		if (i + 1 < x.size())
			os << " ";
	}
	os << std::endl;
	return os;
}
#endif

int main()
{
    vector<int> v;
	std::ofstream ofs("data.txt");
	for (int i = 0; i <= 63; i++) {
		v.push_back(1);
		ofs << v;
	}
	while (v.size()) {
		v.pop_back();
		ofs << v;
	}
}