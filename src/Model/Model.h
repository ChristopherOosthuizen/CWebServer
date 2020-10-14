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
	map<string,function<string(HTTPResponse)>> m_methods;
	Model(function<string(HTTPResponse)> func,const string& method);
	function<string(HTTPResponse)> searchPath(const string& str,const string& method); // search through the code to find the correct function
	void add( const string& str,const string& method,function<string(HTTPResponse)> func);
};
