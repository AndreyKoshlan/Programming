#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

#define _history vector<int>
#define _drinks vector<_drink>

struct outdp {
	int V;
	vector<int> History;
};

struct _drink {
	string Name;
	int Price = 0;
	int V = 0;
	int Count = 0;
};

void printResult(outdp rez, int money, _drinks drinks) {
	int v = 0;
	if (rez.History.size() <= 0) {
		cout << -1;
		return;
	}
	for (int i = 0; i < rez.History.size(); i++) {
		int drinkid = rez.History[i];
		v += drinks[drinkid].V;
		money -= drinks[drinkid].Price;
		drinks[drinkid].Count++;
	}
	for (int i = 0; i < drinks.size(); i++) {
		if (drinks[i].Count > 0) {
			cout << drinks[i].Name << " ";
			cout << drinks[i].Count << endl;
		}
	}
	cout << v << endl << money;
}

outdp DP(int money, _drinks drinks) {
	_history History;
	History.resize(0);
	if (money == 0)
		return outdp{ 0, History };
	int maxv = 0;
	outdp dpvalue;
	for (int i = 0; i < drinks.size(); i++) {
		if (money - drinks[i].Price < 0)
			continue;
		dpvalue = DP(money - drinks[i].Price, drinks);
		if (dpvalue.V + drinks[i].V >= maxv) {
			maxv = dpvalue.V + drinks[i].V;
			History = dpvalue.History;
			History.push_back(i);
		}
	}
	return outdp{ maxv, History };
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int money, n;
	cin >> money >> n;
	_drinks drinks;
	drinks.resize(n);
	for (int i = 0; i < n; i++) {
		string name;
		int price, v = 0;
		cin >> name >> price >> v;
		drinks[i].Name = name;
		drinks[i].Price = price;
		drinks[i].V = v;
		drinks[i].Count = 0;
	}
	outdp rez = DP(money, drinks);
	printResult(rez, money, drinks);
}