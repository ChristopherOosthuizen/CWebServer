#pragma once

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class HTTPRequest {
    string m_message;
    int m_status;
    string m_body;
public:
    HTTPRequest( string message, int status, string body) {
        m_message = message;
        m_status = status;
        m_body = body;
    }
    string toString();
};
