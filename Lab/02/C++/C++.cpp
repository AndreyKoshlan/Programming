#include <iostream>
#include <vector>
#include <iomanip>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
#include "WebHook.h"

using namespace httplib;
using std::string;
using json = nlohmann::json;

WebHook wh;

string replace_str(string str, string source, string nw) {
	SIZE_T sbegin = str.find(source);
	return str.replace(sbegin, source.length(), nw);
}

string readFile(string filename) {
	std::ifstream is(filename);
	std::stringstream ss;
	ss << is.rdbuf();
	return ss.str();
}

void wh_response(const Request& req, Response& res) {
	string block_original = readFile("block.html");
	string blocks = "";
	for (int i = 0; i < wh.Size(); i++) {
		string block_temp = block_original;
		block_temp = replace_str(block_temp, "Webhook URL", wh.Get(i));
		block_temp = replace_str(block_temp, "Webhook URL", wh.Get(i));
		blocks += block_temp+"\n";
	}
	string templ = readFile("template.html");
	templ = replace_str(templ, "{webhooks_list}", blocks);
	//if (req.has_param("del")) {
	//	auto val = req.get_param_value("del");
	//}
	res.set_content(templ, "text/html");
}

int main()
{
	Server svr;                       
	svr.Get("/webhooks", wh_response);
	std::cout << "Start server... OK\n";
	svr.listen("localhost", 1234);
}