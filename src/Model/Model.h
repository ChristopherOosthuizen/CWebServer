#pragma once
#include <map>
#include <string>
#include <functional>
#include <HTTP/HTTPRequest.h>
#include <HTTP/HTTPResponse.h>
using namespace std;
class Model {
public:
	map<string, Model*> m_paths; // all subsequent paths
	function<string(HTTPResponse)> m_base; // the function if the base ends here
	Model(function<string(HTTPResponse)> func);
	function<string(HTTPResponse)> searchPath(const string& str); // search through the code to find the correct function
	void add( const string& str,function<string(HTTPResponse)> func);
};
