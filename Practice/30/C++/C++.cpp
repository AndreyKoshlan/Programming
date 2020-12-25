#include <iostream>
#include <vector>
#include <Windows.h>

using std::vector;

struct Item {
	enum {
		COIN,
		RUNE,
		WEAPON,
		ARMOR
	} ItemType;
	union {
		struct {
			int count;
		} Coin;
		struct {
			int level;
			enum {
				FIRE, WATER, EARTH, AIR
			} element;
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
	} Item;
};

typedef vector<Item> LootBox;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
}
