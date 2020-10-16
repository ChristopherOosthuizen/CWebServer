#pragma once
#include <thread>
#include <Model/Model.h>
#include <Sockets/ServSock.h>
class Server {
Model* m_mod;
public:
	Server(Model* model);
    void run(string address);
    static void handleConnection(int sock,Model* model);
};