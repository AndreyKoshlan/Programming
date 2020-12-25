#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>

using std::vector;

enum IT {
	COIN, RUNE, WEAPON, ARMOR
};

enum ET {
	FIRE, WATER, EARTH, AIR
};

union CT {
	struct {
		int count;
	} Coin;
	struct {
		int level;
		enum ET element;
	} Rune;
	struct {
		int damage;
		int critical;
		int durability;
	} Weapon;
	struct {
		int guard;
		int durability;
	} Armor;
};

struct Item {
	enum IT ItemType;
	union CT Item;
};

typedef vector<Item> LootBox;

class Randomizer {
private:
	LootBox db;
	vector<double> probdb;
public:
	void add(Item x, double prob);
	Item get(int id);
	Item getrnd();
};

void Randomizer::add(Item x, double prob) {
	db.push_back(x);
	if (probdb.size() <= 0) {
		probdb.push_back(prob);
	} else {
		probdb.push_back(prob + probdb[probdb.size()-2]);
	}
}

Item Randomizer::get(int id) {
	return db.at(id);
}

Item Randomizer::getrnd() {
	srand(time(NULL));
	double rnd = (rand() % 10000) / 100; //max = 100
	for (int i = 0; i < db.size(); i++) {
		// //
	}
	Item nothing;
	return nothing;
}

Item operator++(Item x) {
	return x;
}

LootBox& operator<<(LootBox& lb, Item x) {
	lb.push_back(x);
	return lb;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Item x;
}
