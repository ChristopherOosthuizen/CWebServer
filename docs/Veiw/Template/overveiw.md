## View Resource: Template

### Resource 
>This class is a collection of static functions designed to quickly 
insert values into the code template document of any file type.

>The point of this class is to culminate in compile functions, but 
the all the functions are public in case the user wishes to use them

>A template is specified by "<% value%>"
>the syntax <%{value}:{fallBackValue}%> can be used if you want a specialized value in the case of a null value

|Methods||
|-------|-----|
|replace|replaces a single template specified by parameter location|
|replaceAll| replaces all occurrences of a template in a string
|compile| reads a file and returns the result of a replaceAll call on it|

