#include <iostream>
#include <Windows.h>
#include <vector>
#include <numeric>
#include <algorithm>

#define _queue vector<int>

using namespace std;

void DFS(string original, string newstr, _queue queue, int n) {
	if (accumulate(queue.begin(), queue.end(), 0) == n) {
		if (find(queue.begin(), queue.end(), 0) == queue.end()) {
			cout << newstr << " ";
		}
		return;
	}
	for (int i = 0; i < queue.size(); i++) {
		queue[i] += 1;
		DFS(original, newstr + original[i], queue, n);
		queue[i] -= 1;
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n;
	string s;
    cout << "Введите количество символов: ";
	cin >> n;
	cout << "Введите символы: ";
	cin >> s;
	_queue queue;
	queue.resize(s.length());
	DFS(s, "", queue, n);
}