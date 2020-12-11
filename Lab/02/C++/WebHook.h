#pragma once

using namespace httplib;
using std::string;
using json = nlohmann::json;

typedef std::vector<string> webhdata;

class WebHook {
public:
	int Size();
	string GetJSON();
	void Erase(unsigned int id);
	string Get(unsigned int id);
	void PushBack(string val);
	void SaveToFile();
	bool LoadFromFile();
	webhdata data;
	WebHook();
private:
	const string filename = "webhooks.json";
	const string field = "WebHooks";
};

int WebHook::Size() {
	return this->data.size();
}

string WebHook::GetJSON() {
	json j;
	j["WebHooks"] = json::array();
	for (int i = 0; i < data.size(); i++) {
		j["WebHooks"].push_back(this->data[i]);
	}
	std::stringstream ss;
	ss << std::setw(2) << j;
	return ss.str();
}

void WebHook::Erase(unsigned int id) {
	this->data.erase(this->data.begin() + id);
	this->SaveToFile();
}

string WebHook::Get(unsigned int id) {
	return this->data.at(id);
}

void WebHook::PushBack(string val) {
	this->data.push_back(val);
	this->SaveToFile();
}

void WebHook::SaveToFile() {
	std::ofstream os(this->filename);
	os << this->GetJSON() << std::endl;
	os.close();
}

bool WebHook::LoadFromFile() {
	std::ifstream is(this->filename);
	if (is) {
		json j = json::parse(is);
		for (int i = 0; i < j["WebHooks"].size(); i++) {
			this->data.push_back(j["WebHooks"][i]);
		}
		return true;
	}
	else {
		return false;
	}
	is.close();
}

WebHook::WebHook() {
	if (!this->LoadFromFile()) {
		this->SaveToFile();
	}
}