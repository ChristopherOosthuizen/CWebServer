# CWebServer
a web server made in c++ for a search engine project

## Usage
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
this code starts the web server and will return "home" at home
## Contributing
All pull requests are welcome just please dont break the tests that are already put down

## License
[MIT](https://choosealicense.com/licenses/mit/)
