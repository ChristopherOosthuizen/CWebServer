#include "gtest/gtest.h"
#include <Model/Model.h>
#include "ExampleFunctions.h"
TEST(Model, addOneWord) {
	Model model(exploit,"get");
	model.add("hello","get", hello);
	model.add("world","get", world);
	HTTPResponse repo("hello helloss");
	ASSERT_EQ(model.searchPath("hello","get")(repo), "Hello");
	ASSERT_EQ(model.searchPath("world","get")(repo), "world");
	ASSERT_EQ(model.searchPath("","get")(repo), "!");
}

TEST(Model, addMultipleWords) {
	Model model(exploit,"put");
	model.add("hello/world","get", hello);
	model.add("world/word/there","post", world);
	HTTPResponse repo("hello helloss");
	ASSERT_EQ(model.searchPath("hello/world","get")(repo), "Hello");
	ASSERT_EQ(model.searchPath("world/word/there","post")(repo), "world");
	ASSERT_EQ(model.searchPath("","put")(repo), "!");
}
TEST(Model, paths) {
	Model model(NULL,"");
	model.add("world/world","get", hello);
	model.add("world/word/there","get", world);
	model.add("world/word/theres","get", exploit);
    HTTPResponse repo("hello helloss");
	ASSERT_EQ(model.searchPath("world/world","get")(repo), "Hello");
	ASSERT_EQ(model.searchPath("world/word/there","get")(repo), "world");
	ASSERT_EQ(model.searchPath("world/word/theres","get")(repo), "!");

}
TEST(Model, nulls) {
    HTTPRequest request("no page",404,"No page found");
    Model model(NULL,"");
    model.add("world/world","get", hello);
    model.add("world/word/there","get", world);
    model.add("world/word/theres","get", exploit);
    HTTPResponse repo("hello helloss");
    ASSERT_EQ(model.searchPath("world/worl","get")(repo), request.toString());
    ASSERT_EQ(model.searchPath("world/word/there","put")(repo), request.toString());
    ASSERT_EQ(model.searchPath("world/word/theres/hello","get")(repo), request.toString());

}
