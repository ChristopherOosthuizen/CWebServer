
#include <iostream>
#include <Server/Server.h>
#include "exampleClassConfig.h"
int main(){
    Model* model= new Model(write);
    Server serv(model);
    serv.run("8080");
    return 0; 
}
    