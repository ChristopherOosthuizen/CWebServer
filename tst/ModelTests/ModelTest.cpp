#include "gtest/gtest.h"
#include <Model/Model.h>
#include "ExampleFunctions.h"
TEST(Model, addOneWord) {
	Model model(exploit);
	model.add("hello", hello);
	model.add("world", world);
	ASSERT_EQ(model.searchPath("hello")(), "Hello");
	ASSERT_EQ(model.searchPath("world")(), "world");
	ASSERT_EQ(model.searchPath("")(), "!");
}

TEST(Model, addMultipleWords) {
	Model model(exploit);
	model.add("hello/world", hello);
	model.add("world/word/there", world);
	ASSERT_EQ(model.searchPath("hello/world")(), "Hello");
	ASSERT_EQ(model.searchPath("world/word/there")(), "world");
	ASSERT_EQ(model.searchPath("")(), "!");
}
TEST(Model, paths) {
	Model model(NULL);
	model.add("world/world", hello);
	model.add("world/word/there", world);
	model.add("world/word/theres", exploit);
	ASSERT_EQ(model.searchPath("world/world")(), "Hello");
	ASSERT_EQ(model.searchPath("world/word/there")(), "world");
	ASSERT_EQ(model.searchPath("world/word/theres")(), "!");

}