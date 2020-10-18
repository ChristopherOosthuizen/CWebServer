#include <regex>
#include "Template.h"
//replaces the "<% syntax %> with the correct input from map starting and return the end
int Template::replace(string* body,map<string,string>* values , int start) {

    //extract the key inside the brackets while ignoring whitespace
    int location = body->find("<%",start);
    if(location ==-1)
        return -1;
    int end = min(body->length(), body->find("%>",location));
    if(end ==-1)
        end = body->length();
    string key;
    int i;
    for (i = location+2; i < end&& body->at(i) != ':'; i++) {
        if (body->at(i) != ' ')
            key += body->at(i);
    }
    string fallBack ;
    for (; i < end ; i++) {
        if (body->at(i) != ' ')
            fallBack += body->at(i);
    }
    if(fallBack.empty())
        fallBack ="NULL";
    else
        fallBack = fallBack.substr(1,fallBack.length());

        //replaces tag with value
    string value = (*values)[key];
    value = value.empty()?fallBack:value;
    *body = body->substr(0,location)+ value + body->substr(end+2,body->length());


    return location+value.length();
}


//replace all occurrence <% with the correct value
void Template::replaceAll( string* body,map<string,string>* values){
    auto index =body->find("<%");
    while(index != string::npos)
        index = body->find("<%",replace(body,values,index));
}
string *Template::readFile(const string &address) {
    string* result = new string;
    ifstream myfile(address) ;
    if (myfile.is_open())
    {
        string res;
        while ( getline(myfile,res) )
        {
            *result+=res+'\n';
        }
        myfile.close();
    }
    return result;
}

//returns a string representing the inputted files text with all templates replaces.
string Template::compile(const string& fileAddress, map<string,string>* values){
   string *fileContent = readFile(fileAddress);
   replaceAll(fileContent,values);
   string result = *fileContent;
   delete fileContent;
   return result;
}