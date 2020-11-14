#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <direct.h>
#include "json.hpp"

const std::string IN_FILE = "in.json";
const std::string OUT_FILE = "out.json";

struct _user {
	int id;
	int comp_tasks;
};
typedef std::vector<_user> _users;

namespace jsonlib = nlohmann;
using jsonlib::json;

using std::string;
using std::wstring;

void print_save_message() {
	const SIZE_T SIZE = 4096;
	char dir[SIZE];
	_getcwd(dir, SIZE);
	std::cout << "Saved in " << dir << "\\" << OUT_FILE;
	std::cout << std::endl;
}

wstring get_current_dir() {
	WCHAR buff[4096] = { 0 };
	DWORD size = sizeof(buff) / sizeof(buff[0]);
	GetModuleFileName(NULL, buff, size);
	wstring path(buff, size);
	bool isSlashFound = false;
	for (int i = size - 1; i >= 0; i--) {
		if (path[i] == '\\') {
			break;
		}
		path.pop_back();
	}
	return path;
}

int set_working_directory(wstring path) {
	return _wchdir(path.c_str());
}

json load_from_executable_path(string fileName) {
	wstring path = get_current_dir();
	set_working_directory(path);
	std::ifstream is(fileName, std::ios::binary);
	json j = json::parse(is);
	return j;
}

json load_json_file(string fileName) {
	std::ifstream is(fileName, std::ios::binary);
	if (is.is_open())
	{
		json j = json::parse(is);
		return j;
	} else  {
		return load_from_executable_path(fileName);
	}
}

void add_new_user(_users &users, int uid) {
	_user user;
	user.comp_tasks = 1;
	user.id = uid;
	users.push_back(user);
}

void add_completed_task(_users &users, int uid) {
	for (int i = 0; i < users.size(); i++) {
		if (users[i].id == uid) {
			users[i].comp_tasks++;
			return;
		}
	}
	add_new_user(users, uid);
}

void parse_users_json_file(_users &users, string fileName) {
	json j = load_json_file(fileName);
	for (int i = 0; i < j.size(); i++) {
		int uid = j[i]["userId"];
		bool ucomp = j[i]["completed"];
		if (ucomp)
			add_completed_task(users, uid);
	}
}

void create_report_json_file(_users &users, string fileName) {
	json j = json::array();
	for (int i = 0; i < users.size(); i++)
	{
		json uj;
		uj["userId"] = users[i].id;
		uj["task_completed"] = users[i].comp_tasks;
		j.push_back(uj);
	}
	std::ofstream os(fileName);
	os << std::setw(2) << j << std::endl;
	print_save_message();
}

int main()
{
	_users users;
	parse_users_json_file(users, IN_FILE);
	create_report_json_file(users, OUT_FILE);
}