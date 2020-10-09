#pragma once
#include <string>
#include <HTTP/HTTPResponse.h>
using namespace std;

string hello(HTTPResponse rest) {
	return "Hello";
}
string world(HTTPResponse rest){
	return "world";
}
string exploit(HTTPResponse rest) {
	return "!";
}
extern string hello(HTTPResponse rest);
extern string world(HTTPResponse rest);
extern string exploit(HTTPResponse resj);
