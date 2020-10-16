# HTTPRequest

> slightly mislabeled this is for the server to send back to the user.

> point of this is to take a message from the user the user.

## class constructor parameters

|name|type| description| 
|---|----|----|
|message|string| what the message type for the request|
|status| int| the status code of the request|
|body|  string| the data that the user want to send to the client|

## methods

|method| type| description|
|-----|-----|-----|
|[toString](toString.md)|string| return the parameters as a http request while auto adding content-length to the attributes|


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

