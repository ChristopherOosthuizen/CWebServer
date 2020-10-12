#include "gtest/gtest.h"
#include <Model/Model.h>
#include "ExampleFunctions.h"
TEST(Model, addOneWord) {
	Model model(exploit);
	model.add("hello", hello);
	model.add("world", world);
	HTTPResponse repo("hello helloss");
	ASSERT_EQ(model.searchPath("hello")(repo), "Hello");
	ASSERT_EQ(model.searchPath("world")(repo), "world");
	ASSERT_EQ(model.searchPath("")(repo), "!");
}

TEST(Model, addMultipleWords) {
	Model model(exploit);
	model.add("hello/world", hello);
	model.add("world/word/there", world);
	HTTPResponse repo("hello helloss");
	ASSERT_EQ(model.searchPath("hello/world")(repo), "Hello");
	ASSERT_EQ(model.searchPath("world/word/there")(repo), "world");
	ASSERT_EQ(model.searchPath("")(repo), "!");
}
TEST(Model, paths) {
	Model model(NULL);
	model.add("world/world", hello);
	model.add("world/word/there", world);
	model.add("world/word/theres", exploit);
    HTTPResponse repo("hello helloss");
	ASSERT_EQ(model.searchPath("world/world")(repo), "Hello");
	ASSERT_EQ(model.searchPath("world/word/there")(repo), "world");
	ASSERT_EQ(model.searchPath("world/word/theres")(repo), "!");

}
