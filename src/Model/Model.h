#pragma once
#include <map>
#include <string>
#include <functional>
using namespace std;
class Model {
public:
	map<string, Model*> m_paths; // all subsequent paths
	function<string()> m_base; // the function if the base ends here
	Model(function<string()> func);
	function<string()> searchPath(const string& str); // search through the code to find the correct function
	void add( const string& str,function<string()> func);
};
