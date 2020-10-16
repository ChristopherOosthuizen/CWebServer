# class: HTTPResponse
> used to receive data from users through the whole request.
> this class is not  meant to be constructed by the user, but they are supposed to be created by the server class
>. This will be used by functions put into the model class.

## parameters
|name| type| description|
|-----|-----|-----|
|body|string| the raw HTTPRequest given by the client|

## function

|name| type| description|
|-----|-----|-----|
|getMethod| string| returns the method ex: GET,PUT
|getAddress| string| returns the address of the url ex: /hello