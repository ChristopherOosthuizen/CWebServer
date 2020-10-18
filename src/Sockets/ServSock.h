//
// Created by Chris on 9/27/2020.
//
#pragma once
#ifndef FAKESQL_SERVSOCK_H
#define FAKESQL_SERVSOCK_H


#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <string>
using namespace std;
class ServSock {
public:
    int m_socket;
    int m_addrlen;
    struct sockaddr_in m_address;
    ServSock(int port);
    int connect();
    static char read(int sock);
    static void write(int sock,std::string message);
    static string readAll(int sock);

};


#endif //FAKESQL_SERVSOCK_H
