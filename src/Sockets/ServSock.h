//
// Created by Chris on 9/27/2020.
//

#ifndef FAKESQL_SERVSOCK_H
#define FAKESQL_SERVSOCK_H
#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;
class ServSock {
    SOCKET m_sock;
public:
    ServSock(char* port);
    ~ServSock();
    static char read(SOCKET sock);
    static std::string readAll(SOCKET sock);
    static void write(SOCKET sock,std::string message);
    SOCKET connect();
    static void close(SOCKET sock);
};


#endif //FAKESQL_SERVSOCK_H
