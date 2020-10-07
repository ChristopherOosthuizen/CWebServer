#include "HTTPResponse.h"

HTTPResponse::HTTPResponse(string str) {
	int current = 0;
	current = str.find(' ');
	m_method = str.substr(0, current);
	m_address = str.substr(current + 1, str.find(' ', current+1)-4);
}