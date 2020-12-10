#include <iostream>
#include <Windows.h>
#include <map>

typedef std::map<int, int> fact;

fact sum_map(fact x1, fact x2) {
	for (auto z = x2.begin(); z != x2.end(); ++z) {
		if (x1.count(z->first)) {
			x1[z->first] += x2[z->first];
		} else {
			x1.insert({ z->first, z->second });
		}
	}
	return x1;
}

fact get_factors(unsigned int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			int j = x / i;
			return sum_map(get_factors(i), get_factors(j));
		}
	}
	fact rez = { { x, 1 } };
	return rez;
}

void print_factorization(unsigned int n) {
	fact f = get_factors(n);
	auto x = f.begin();
	while (x != f.end()) {
		std::cout << x->first;
		if (x->second > 1) {
			std::cout << "^" << x->second;
		}
		if (++x != f.end()) std::cout << "*";
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	unsigned int x;
    std::cout << "Введите число: ";
	std::cin >> x;
	print_factorization(x);
}