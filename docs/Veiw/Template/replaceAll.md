# Template Function: replaceAll
replace all implementations of <% %> with the correct values and returns a string of it by calling
the [replace](replace.md) function.
## Parameters
|Parameters | type| description|
|-----------|----|-------|
|body|string* |  the pointer the the string that will have all of its templates replaces|
|values| map<string,string>| the values used to fill on templates

## example
### code
```
auto* values = new map<string,string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    auto*  result = new string("Hi, <%there%><%hello%>, <%user%>");
    Template::replaceAll(result,values);
```
### output
```
Hi, Hellothere, chris
```