#include "HTTPRequest.h"
#include <sstream>

string HTTPRequest::toString() {
	const int length = m_message.size() + m_body.size() + 600;
	char* buff = (char*)malloc(length);
	int len = m_body.length();
	snprintf(buff, length, "HTTP/1.1 %d %s\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s", m_status, m_message.c_str(), len, m_body.c_str());
	string str = string(buff);
	free(buff);
	return str;
}