//
// Created by Chris on 10/14/2020.
//

#ifndef WEBSERVER_VIEWS_H
#define WEBSERVER_VIEWS_H
#include <string>
#include <HTTP/HTTPResponse.h>
#include <HTTP/HTTPRequest.h>
#include <View/Template.h>
using namespace std;
string base(HTTPResponse response){
    auto* data = Template::readFile("resources/home.html");
    HTTPRequest request("OK",200,*data);
    delete data;
    return request.toString();
}
string home(HTTPResponse response){
    HTTPRequest request("OK",200,"hello");
    cout<< request.toString();
    return request.toString();
}
#endif //WEBSERVER_VIEWS_H
