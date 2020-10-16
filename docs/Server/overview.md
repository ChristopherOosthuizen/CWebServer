# class: Server
this is the main class of the project use this to set up the server.

## constructor parameters

|name|type|description|
|----|----|-----------|
|run| void| runs the server on a specified port|
|handleConnection|void| handles a single connection|

## example

### code 
```
string base(HTTPResponse response){
    auto data = "hello there"
    HTTPRequest request("OK",200,data);
    return request.toString();
}
string home(HTTPResponse response){
    HTTPRequest request("OK",200,"hello");
    return request.toString();
}
int main(){
    Model* mod = new Model(base,"GET");
    mod->add("home","GET",home);
    Server server(mod);
    server.run("8080");
    return 0;
}
```

### output
this should start the server on 8080 so if you go to your browser address of localhost:8080 you should see the message hello there. 

