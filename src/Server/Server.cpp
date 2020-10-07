#include "Server.h"
Server::Server(Model* model) {
	m_mod = model;
}
int handleConnection(SOCKET sock) {
    string inputs;
    try {
        inputs = ServSock::readAll(sock);
    }
    catch (string& str) {
        return 0;
    }
    HTTPResponse responce(inputs);
    cout << responce.getAddress() << endl;
    HTTPRequest request("OK", 200, "Hello there");
    ServSock::write(sock, request.toString());
    return 1;
}
void Server::run(string address) {
    ServSock sock("8080");
    while (1) {
        SOCKET socker = sock.connect();
        thread thread(handleConnection, socker);
        thread.detach();
    }
}