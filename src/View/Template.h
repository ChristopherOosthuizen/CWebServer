#pragma once
#include <map>

#include <string>
#include <fstream>

using namespace std;

class Template {
public:
    static string *readFile(const string& address);
    static int replace(string* body,map<string,string>* values , int start);
    static void replaceAll( string* body,map<string,string>* values);
    static string compile(const string& fileAddress, map<string,string>* values);
};