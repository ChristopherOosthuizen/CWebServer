//
// Created by Chris on 10/14/2020.
//
#include <Server/Server.h>
#include "views.h"
int main(){
    Model* mod = new Model(base,"GET");
    mod->add("home","GET",home);
    Server server(mod);
    server.run("8080");
    return 0;
}