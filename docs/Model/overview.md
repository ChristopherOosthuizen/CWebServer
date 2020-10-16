# Model
used to run on the server as a template for the view

## parameters

|name|type|description|
|----|----|-----------|
|func|function<string(HTTPResponse)>| the method used for the base view for your website|
|method|string| the HTTP method used for the base|

## methods

|name|type|description|
|----|----|-----------|
|searchPath| function<string(HTTPResponse)>| returns the method based on a specified path|
|add| void| adds a method stored in the specified path.
