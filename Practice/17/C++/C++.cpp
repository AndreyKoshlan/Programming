#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 36;
const int MIN_SIZE = 0;
const int SIZE = abs(MAX_SIZE)+abs(MIN_SIZE)+1;
const int MAX_PLAYS = 12; //K
const string LAYOUT = "Z101010101001010101101010101001010101"; //RED = 1 BLACK = 0 ZERO = Z

struct NumberElement {
	int counted = 0;
	int lastCount = -1;
};

struct _Data {
	vector<NumberElement> NumberElements;
	vector<char> ColourStack;
	int playCounter = 0;
};

_Data InitData() {
	_Data Data;
	Data.NumberElements.resize(SIZE);
	for (int i = 0; i <= MAX_PLAYS-1; i++)
		Data.ColourStack.push_back('-');
	return Data;
}

void Calculate(_Data &Data, int id) {
	Data.NumberElements[id].counted += 1;
	Data.NumberElements[id].lastCount = Data.playCounter;
	Data.ColourStack.pop_back();
	Data.ColourStack.insert(Data.ColourStack.begin(), LAYOUT[id]);
}

void PrintMostCommonNumbers(_Data &Data) {
	int max = -1;
	for (int id = MIN_SIZE; id <= MAX_SIZE; id++) {
		if (Data.NumberElements[id].counted > max)
			max = Data.NumberElements[id].counted;
	}
	for (int id = MIN_SIZE; id <= MAX_SIZE; id++) {
		if (Data.NumberElements[id].counted == max)
			cout << id << " ";
	}
	cout << endl;
}

void PrintMissingNumbers(_Data &Data) {
	int k = min(MAX_PLAYS - 1, Data.playCounter);
	for (int id = MIN_SIZE; id <= MAX_SIZE; id++) {
		if (Data.playCounter - Data.NumberElements[id].lastCount > k) {
			cout << id << " ";
		}
	}
	cout << endl;
}

void PrintColourStats(_Data &Data) {
	int RED = 0;
	int BLACK = 0;
	for (int id = 0; id <= Data.ColourStack.size()-1; id++) {
		if (Data.ColourStack[id] == '0')
			BLACK++;
		if (Data.ColourStack[id] == '1')
			RED++;
	}
	cout << RED << " " << BLACK << endl;
}

void PrintResult(_Data &Data) {
	PrintMostCommonNumbers(Data);
	PrintMissingNumbers(Data);
	PrintColourStats(Data);
	cout << endl;
}

int main() {
	_Data Data = InitData();
	int id;
	cin >> id;
	while (id != -1) {
		Calculate(Data, id);
		PrintResult(Data);
		Data.playCounter += 1;
		cin >> id;
	}
}