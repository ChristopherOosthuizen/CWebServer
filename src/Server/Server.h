#pragma once
#include <thread>
#include <HTTP/HTTPResponse.h>
#include <HTTP/HTTPRequest.h>
#include <Model/Model.h>
#include <Sockets/ServSock.h>
class Server {
Model* m_mod;
public:
	Server(Model* model);
    void run(string address);
};