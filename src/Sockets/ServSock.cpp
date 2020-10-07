//
// Created by Chris on 9/27/2020.
//



#include <cstdio>
#include <iostream>
#include "ServSock.h"
#pragma comment (lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1
#define DEFAULT_PORT "8080"

char ServSock::read(SOCKET ClientSocket){
    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    int iResult;
    iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
    return recvbuf[0];
}
void ServSock::close(SOCKET sock){
    closesocket(sock);
}
SOCKET ServSock::connect() {
    SOCKET client = INVALID_SOCKET;
    client = accept(m_sock,NULL,NULL);
    return client;
}

ServSock::ServSock(char *port) {
    WSADATA wsaData;
    int iResult;

    m_sock = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;


    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);

    m_sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    iResult = bind( m_sock, result->ai_addr, (int)result->ai_addrlen);

    freeaddrinfo(result);

    iResult = listen(m_sock, SOMAXCONN);

}

ServSock::~ServSock() {
    WSACleanup();
    closesocket(m_sock);
}

void ServSock::write(SOCKET sock,std::string message) {
    send(sock,message.c_str(),message.length(),0);
}

std::string ServSock::readAll(SOCKET sock) {
    std::string result;
    char c;
    int count =0;
    int times = 0;
    do{
        int count = 0;
        do {
            c = ServSock::read(sock);
            count++;
            result +=c;
        } while (c >0&&c != '\n');
        if (count == 2)
            break;
    }while(c > 0 );
    return result;
}

