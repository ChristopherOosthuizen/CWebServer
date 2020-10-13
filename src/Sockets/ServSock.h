//
// Created by Chris on 9/27/2020.
//

#ifndef FAKESQL_SERVSOCK_H
#define FAKESQL_SERVSOCK_H


#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
using namespace std;
class ServSock {
      int m_sock;
      int m_addrlen;
public:
      struct sockaddr_in m_address;
      ServSock(int port);
      int connect();
      static char read(int sock);
      static void write(int sock,std::string message);
    static string readAll(int sock);
    static void close(int sock);
    ~ServSock();

};


#endif //FAKESQL_SERVSOCK_H
