
#include <iostream>
#include <Server/Server.h>
#include "exampleClassConfig.h"
#include <View/Template.h>
string writess(HTTPResponse reponse){
    auto* values = new map<string,string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    HTTPRequest request("OK",200,"Hi there my friend");
    return request.toString();
}
int main(){
    std::function<string(HTTPResponse)> str = writess;
    auto* model= new Model(str,"GET");
    Server serv(model);
    serv.run("8080");
    return 0; 
}
    
