#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <Windows.h>

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
							{ "Molyneux P", 1, { {"mathematics", 5}, {"physics", 5},
												 {"history", 5}, {"programming", 5} }
							},
							{ "Molyneux P", 1, { {"mathematics", 5}, {"physics", 5},
												 {"history", 5}, {"programming", 5} }
							}
						};
	std::cout << v;
}