#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <Windows.h>
#include <time.h> 

using std::string;
using std::vector;
using std::ostream;
using std::map;

const int MAX_SIZE_NAME = 12;
const int MAX_SIZE_GROUP = 7;
const int MAX_SIZE_MATH = 6;
const int MAX_SIZE_PHYS = 6;
const int MAX_SIZE_HIST = 6;
const int MAX_SIZE_PROG = 6;

struct Student {
	string name;
	byte group;
	map<string, byte> exams;
};

bool operator>(Student a, Student b) {
	return a.name > b.name;
}

bool operator<(Student a, Student b) {
	return a.name < b.name;
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

string get_table_border() {
	return '+' + string(MAX_SIZE_NAME, '-')  + 
		   '+' + string(MAX_SIZE_GROUP, '-') +
		   '+' + string(MAX_SIZE_MATH, '-')  +
		   '+' + string(MAX_SIZE_PHYS, '-')  +
		   '+' + string(MAX_SIZE_HIST, '-')  +
		   '+' + string(MAX_SIZE_PROG, '-')  + "+\n";
}

string get_table_value(string x, int limit) {
	if (x.length() > limit - 2) {
		x = x.substr(0, max(0, limit - 4));
		x = x + "..";
	}
	return "| " + x + std::string(max(0, limit - x.length() - 1), ' ');		  
}

string get_table_header() {
	return get_table_border() + get_table_value("Name", MAX_SIZE_NAME)
		+ get_table_value("Group", MAX_SIZE_GROUP)
		+ get_table_value("Math", MAX_SIZE_MATH)
		+ get_table_value("Phys", MAX_SIZE_PHYS)
		+ get_table_value("Hist", MAX_SIZE_HIST)
		+ get_table_value("Prog", MAX_SIZE_PROG) + "|\n";
}

string get_part_table(Student s) {
	return get_table_border() + get_table_value(s.name, MAX_SIZE_NAME)
		   + get_table_value(std::to_string(s.group), MAX_SIZE_GROUP) 
		   + get_table_value(std::to_string(s.exams["mathematics"]), MAX_SIZE_MATH) 
		   + get_table_value(std::to_string(s.exams["physics"]), MAX_SIZE_PHYS)
		   + get_table_value(std::to_string(s.exams["history"]), MAX_SIZE_HIST)
		   + get_table_value(std::to_string(s.exams["programming"]), MAX_SIZE_PROG) 
		   + "|\n";
}
ostream& operator<<(ostream& os, Student s) {
	os << get_table_header() << get_part_table(s) << get_table_border();
	return os;
}

ostream& operator<<(ostream& os, vector<Student> s) {
	os << get_table_header();
	for (int i = 0; i < s.size(); i++) {
		os << get_part_table(s[i]);
	}
	os << get_table_border();
	return os;
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<Student> v = {
					{ "Allen K", 9, { {"mathematics", 4}, {"physics", 3},
										 {"history", 4}, {"programming", 3} }
					},
					{ "Hill F", 5, { {"mathematics", 5}, {"physics", 4},
										 {"history", 2}, {"programming", 5} }
					},
					{ "Anderson R", 1, { {"mathematics", 5}, {"physics", 5},
										 {"history", 5}, {"programming", 5} }
					},
					{ "Adams K", 2, { {"mathematics", 3}, {"physics", 5},
										 {"history", 4}, {"programming", 3} }
					},
					{ "Brown D", 1, { {"mathematics", 5}, {"physics", 5},
										 {"history", 5}, {"programming", 5} }
					},
					{ "Davis A", 5, { {"mathematics", 3}, {"physics", 2},
										 {"history", 3}, {"programming", 5} }
					},
					{ "Clark B", 4, { {"mathematics", 4}, {"physics", 4},
										 {"history", 4}, {"programming", 4} }
					},
					{ "Flores M", 8, { {"mathematics", 2}, {"physics", 2},
										 {"history", 2}, {"programming", 2} }
					},
					{ "Carter J", 7, { {"mathematics", 5}, {"physics", 3},
										 {"history", 4}, {"programming", 3} }
					},
					{ "Campbell C", 8, { {"mathematics", 5}, {"physics", 3},
										 {"history", 4}, {"programming", 2} }
					}
	};
	vector<Student> badguys;
	for (int i = 0; i < v.size(); i++) {
		if ((v[i].exams["mathematics"] == 2) || (v[i].exams["physics"] == 2) ||
			(v[i].exams["history"] == 2) || (v[i].exams["programming"] == 2)) {
				badguys.push_back(v[i]);
		}
	}

	//Vector
	std::cout << BozoSort(badguys) << std::endl;

	std::cout << "Expulsion" << "\n\n";

	//An element
	srand(time(NULL));
	if (badguys.size() > 0) {
		std::cout << badguys[rand() % badguys.size()];
	} else {
		std::cout << "Not found";
	}
}