# class method: toString
a simple method that just converts the class to string form as a http response.

## example
### code
```
   HTTPRequest request("OK",200,"hello");
   return request.toString();
```

### output
```
HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: 5

hello
```