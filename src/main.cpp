
#include <iostream>
#include <Server/Server.h>
#include "exampleClassConfig.h"
string writess(HTTPResponse reponse){
    HTTPRequest request("OK",200,"Hi there my friend");
    return request.toString();
}
int main(){
    std::function<string(HTTPResponse)> str = writess;
    auto* model= new Model(str);
    Server serv(model);
    serv.run("8080");
    return 0; 
}
    
