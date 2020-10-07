#pragma once
#include <string>
using namespace std;

string hello() {
	return "Hello";
}
string world() {
	return "world";
}
string exploit() {
	return "!";
}
extern string hello();
extern string world();
extern string exploit();
