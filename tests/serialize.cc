#include <gtest/gtest.h>
#include <models/categories_model.h>

TEST(Serialize, Serialize_cat){
    ICategory category("cat_test", false, nullptr);
    string expected = "{\"children\":[],\"isHidden\":false,\"title\":\"cat_test\"}";
    json cat_j = category.serialize();

    string result = to_string(cat_j);

    EXPECT_TRUE(result == expected);
}