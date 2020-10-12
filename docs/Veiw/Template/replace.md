# Template function: replace
Replace the instance of <%{value}%> with the correct value with the replacing it with null if empty
and returns the new end of the tag

## Path parameters
|Parameters|type|description|
|---------|---|----|
|start| int| specifies the start of the search
|values| map<string,string>| values and there keys
|body| string| actual values held inside
## example
#### code
```
auto* values= new map<string,string>;
(*map)["user"] = "chris";
(*map)["email"] = "mail@gmail.com";
auto* body = new string("FIRSTNAME:<%user%> LASTNAME:<%lastName%> EMAIL: <%email:none%> PASSWORD:<%password:encripted%>");
replace( body,map,0);
replace( body,map,0);
replace( body,map,0);
replace( body,map,0);
std::cout<< *body;
```
#### return 
``` 
FIRSTNAME:chris LASTNAME:NULL EMAIL:mail@gmail.com PASSWORD:encrypted
```