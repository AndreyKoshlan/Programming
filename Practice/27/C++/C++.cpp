#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

typedef std::vector<double> _stack;
typedef std::vector<int> list;
const unsigned int MAXK = 5;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	_stack stack(MAXK /*5*/, INFINITY);
	list lst;
	int n, x;

	std::cout << "Введите число N: ";
	std::cin >> n;
	std::cout << "Введите N чисел: ";
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		if (stack[MAXK - 1] > (double)x) {
			stack.push_back((double)x);
			std::sort(stack.begin(), stack.end());
			if (stack.size() > MAXK)
				stack.pop_back();
		}
		for (int j = stack.size() - 1; j >= 0; j--) {
			if (!isinf(stack[j])) std::cout << stack[j] << " ";
		}
		std::cout << std::endl;
	}
}