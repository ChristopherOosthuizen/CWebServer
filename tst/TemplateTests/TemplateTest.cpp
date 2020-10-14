//
// Created by christopher on 10/9/20.
//

#include "gtest/gtest.h"
#include <View/Template.h>

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
TEST(Replace ,basic){
    auto* values = new map<string,string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    auto*  result = new string("Hi, <%there%><%hello%>, <%user%>");
    int start = Template::Template::replace(result,values,4);
    start = Template::replace(result,values,start);
    Template::replace(result,values,start+2);
    ASSERT_EQ("Hi, Hellothere, chris",*result);

}
TEST(Replace,brokenTags){
    auto* values = new map<string,string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    auto*  result = new string("Hi, <%there%>   <%hello%>, <%great%> <%user%>");
    int start = Template::replace(result,values,4);
    start = Template::replace(result,values,0);
    Template::replace(result,values,0);
    Template::replace(result,values,0);
    ASSERT_EQ("Hi, Hello   there, NULL chris",*result);
}
TEST(Replace,fallBack){
    auto* values = new map<string,string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    auto*  result = new string("Hi, <%there:they%>, <%great:right%> <%user%>");
    int start = Template::Template::replace(result,values,4);
    start = Template::replace(result,values,0);
    Template::replace(result,values,0);
    Template::replace(result,values,0);
    ASSERT_EQ("Hi, Hello, right chris",*result);
}

TEST(Replace,unFilledTags){
    auto* values = new map<string,string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    auto*  result = new string("Hi, <%there%>   <%hello%>, <%great%> <%user%>");
    int start = Template::replace(result,values,4);
    start = Template::replace(result,values,start);
    Template::replace(result,values,start);
    Template::replace(result,values,start+2);
    ASSERT_EQ("Hi, Hello   there, NULL chris",*result);
}

TEST(ReplaceAll,basic) {
    auto *values = new map<string, string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    auto *result = new string("Hi, <%there%><%hello%>, <%user%>");
    Template::replaceAll(result, values);
    ASSERT_EQ(*result,"Hi, Hellothere, chris");
}
TEST(ReplaceAll,fallBack){
    auto* values = new map<string,string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    auto*  result = new string("Hi, <%there:they%>, <%great:right%> <%user%>");
    Template::replaceAll(result,values);
    ASSERT_EQ("Hi, Hello, right chris",*result);
}
TEST(ReplaceAll,unfilledTags){
    auto* values = new map<string,string>();
    (*values)["hello"] = "there";
    (*values)["there"] = "Hello";
    (*values)["user"] = "chris";
    auto*  result = new string("Hi, <%there:they%>, <%great%> <%user%>");
    Template::replaceAll(result,values);
    ASSERT_EQ("Hi, Hello, NULL chris",*result);
}
TEST(Replace,docExample){

    auto* nap = new map<string,string>;
    (*nap)["user"] = "chris";
    (*nap)["email"] = "mail@gmail.com";
    auto* body = new string("FIRSTNAME:<%user%> LASTNAME:<%lastName%> EMAIL: <%email:none%> PASSWORD:<%password:encripted%>");
    Template::replace( body,nap,0);
    Template::replace( body,nap,0);
    Template::replace( body,nap,0);
    Template::replace( body,nap,0);
    std::cout<< *body;
}
TEST(Copile,basic){
    auto* nap = new map<string,string>;
    (*nap)["there"] = "chris";
    (*nap)["hello"] = "mail@gmail.com";
    SetCurrentDirectory("../../../CWebServer/tst/TemplateTests");
    string body = Template::compile("basic.html",nap);
     ASSERT_EQ(body,"<html>\n\nmail@gmail.com\nchris\nlike\nNULL\n\n</html>\n");
}