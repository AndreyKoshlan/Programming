#include <iostream>
#include <fstream>
#include <iomanip>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>

const std::string API_KEY = "e88ae3e431bbe8ed808fd00b5faa66b7";

namespace jsonlib = nlohmann;
using namespace httplib;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using jsonlib::json;

string weather_data;
int currtime = 0;

string http_get(const char* host, const char* path) {
	Client cli(host);
	cout << "GET: " << host << path;
	auto res = cli.Get(path);
	if (res) {
		if (res->status == 200) {
			cout << res->body << endl << endl;
			return res->body;
		}
		else {
			cout << " Status code: " << res->status << std::endl;
		}
	}
	else {
		auto err = res.error();
		cout << " Error code: " << err << std::endl;
	}
	cout << endl;
	return "";
}

int get_unix_time() {
	string timestr = "";
	timestr = http_get("http://worldtimeapi.org", "/api/timezone/Europe/Simferopol");
	if (timestr != "") {
		json j = json::parse(timestr, nullptr, false);
		return j["unixtime"];
	}
	return 0;
}

string download_weather() {
	return http_get("http://api.openweathermap.org", ("/data/2.5/onecall?lang=ru&lat=44.952116&lon=34.102411&appid="+API_KEY).c_str());
}

void update_weather() {
	weather_data = download_weather();
}

int get_weather_next_id() {
	if (weather_data == "") return -1;
	json j = json::parse(weather_data);
	for (int i = 0; i < j["hourly"].size(); i++) {
		if (j["hourly"][i]["dt"] > currtime) {
			return i;
		}
	}
	return -1;
}

int refresh_data() {
	currtime = get_unix_time();
	int id = get_weather_next_id();
	if (id < 0) {
		update_weather();
		id = get_weather_next_id();
	}
	return id;
}

double get_weather_param(int id, string param) {
	if (weather_data != "") {
		json j = json::parse(weather_data);
		return j["hourly"][id][param];
	}
	return 0;
}

string get_weather_description(int id) {
	if (weather_data != "") {
		json j = json::parse(weather_data);
		if (j["hourly"][id]["weather"].size() > 0)
			return j["hourly"][id]["weather"][0]["description"];
	}
	return "";
}

string get_weather_icon(int id) {
	if (weather_data != "") {
		json j = json::parse(weather_data);
		if (j["hourly"][id]["weather"].size() > 0)
			return j["hourly"][id]["weather"][0]["icon"];
	}
	return "";
}

bool get_weather_data(double& temp, string& description, string& icon) {
	try {
		int id = refresh_data();
		if (id < 0) {
			return false;
		}
		temp = get_weather_param(id, "temp") - 273;
		description = get_weather_description(id);
		icon = get_weather_icon(id);
	}
	catch (...) {
		return false;
	}
	return true;
}

string replace_str(string str, string source, string nw) {
	SIZE_T sbegin = str.find(source);
	return str.replace(sbegin, source.length(), nw);
	return str;
}

string create_widget(int temp, string description, string icon) {
	std::ifstream is("widget.html");
	std::stringstream ss;
	ss << is.rdbuf();
	string s = ss.str();
	
	s = replace_str(s, "{hourly[i].temp}", std::to_string(temp));
	s = replace_str(s, "{hourly[i].weather[0].description}", description);
	s = replace_str(s, "{hourly[i].weather[0].icon}", icon);
	
	return s;
}

string create_raw(int temp, string description) {
	std::stringstream ss;
	json j;
	j["temp"] = temp;
	j["description"] = description;
	ss << std::setw(2) << j << std::endl;
	return ss.str();
}

void main_response(const Request& req, Response& res) {
	double temp = 0;
	string description = "", icon = "";
	if (get_weather_data(temp, description, icon))
		res.set_content(create_widget(round(temp), description, icon), "text/html; charset=UTF-8");
	else
		res.set_content("Service is unavailable", "text/html");
}

void raw_response(const Request& req, Response& res) {
	double temp = 0;
	string description = "", icon = "";
	if (get_weather_data(temp, description, icon))
		res.set_content(create_raw(round(temp), description), "text/plain; charset=UTF-8");
	else
		res.set_content("Service is unavailable", "text/html");
}

void StartServer(Server& svr) {
	std::cout << "Start server... OK\n";
	svr.Get("/", main_response);   
	svr.Get("/raw", raw_response);
	svr.listen("0.0.0.0", 3000);
}

int main()
{
	Server svr;
	StartServer(svr);
}