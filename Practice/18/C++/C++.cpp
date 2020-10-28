#include <iostream>
#include <vector>

#define voc vector<int>

using namespace std;

const vector<string> Words = { "hallo", "klempner", "das", "ist", "fantastisch", "fluggegecheimen" };

double GetCharProb(int CharID, double words_count, voc Vocabulary) {
	return Vocabulary[CharID] / words_count;
}

void Init(voc &Vocabulary, int &words_count) {
	Vocabulary.resize(256); //overflow?
	words_count = 0;
	for (int i = 0; i < Words.size(); i++) {
		string s = Words[i];
		words_count += s.length();
		for (int j = 0; j < s.length(); j++) {
			int CharID = int(s[j]);
			Vocabulary[CharID] += 1;
		}
	}
}

int main() {
	string x;
	voc Vocabulary;
	int words_count;
	Init(Vocabulary, words_count);
	cin >> x;
	double probability = 1;
	for (int i = 0; i < x.length(); i++) {
		int CharID = int(x[i]);
		probability *= GetCharProb(CharID, words_count, Vocabulary);
	}
	cout << probability << endl;
}