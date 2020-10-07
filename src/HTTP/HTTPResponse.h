#pragma once
#include <string>
#include <map>
using namespace std;
class HTTPResponse {
	map<string, string> m_attributes;
	string m_method;
	string m_address;
public:
	HTTPResponse(string input);
	string getMethod() { return m_method; };
	string getAddress() { return m_address; };
};