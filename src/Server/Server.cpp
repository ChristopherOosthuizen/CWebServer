#include "Server.h"
Server::Server(Model* model) {
	m_mod = model;
}
void Server::handleConnection(int sock,Model* model) {
    string inputs;
    try {
        inputs = ServSock::readAll(sock);
    }
    catch (string& str) {
        return;
    }
    HTTPResponse response(inputs);
    string address = response.getAddress();
    address = address.substr(1,address.length());
    string method = response.getMethod();
    cout<<method<<'\n';
    cout<<address<<'\n';
    auto func = model->searchPath(address,method);
      //checks to see if the function is valid becuase you cant assign a invalid function to a varible
      if(func)
        ServSock::write(sock,func(response));
      closesocket(sock);
}
void Server::run(string address) {
    ServSock sock(8080);
    while (1) {
        int socker = sock.connect();
        thread obj(handleConnection, socker,m_mod);
        obj.detach();
    }
}