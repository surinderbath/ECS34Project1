#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string Base = "Hello";

    EXPECT_EQ(StringUtils::Slice(Base,0), "Hello");
    EXPECT_EQ(StringUtils::Slice(Base,1), "ello");
}

TEST(StringUtilsTest, Capitalize){
    std::string Base = "Hello";

    EXPECT_EQ(StringUtils::Capitalize(Base),"Hello");
    EXPECT_EQ(StringUtils::Capitalize(std::string()),"");
    EXPECT_EQ(StringUtils::Capitalize(" hello")," hello");
    EXPECT_EQ(StringUtils::Capitalize("HELLO"),"Hello");
}

TEST(StringUtilsTest, Upper){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Upper(Base), "HELLO");
}

TEST(StringUtilsTest, Lower){
    std::string Base = "HELLO";

    EXPECT_EQ(StringUtils::Lower(Base), "hello");
    
}

TEST(StringUtilsTest, LStrip){
    std::string Base = "  hello";

    EXPECT_EQ(StringUtils::LStrip(Base), "hello");
    EXPECT_EQ(StringUtils::LStrip(""), "");
    EXPECT_EQ(StringUtils::LStrip("\thi"), "hi");
    EXPECT_EQ(StringUtils::LStrip("\th i"), "h i");
    EXPECT_EQ(StringUtils::LStrip("\t\nhi"), "hi");
    EXPECT_EQ(StringUtils::LStrip("\thi  "), "hi  ");
    
}

TEST(StringUtilsTest, RStrip){
    std::string Base = "hello   ";

    EXPECT_EQ(StringUtils::RStrip(Base), "hello");
    EXPECT_EQ(StringUtils::RStrip(""), "");
    EXPECT_EQ(StringUtils::RStrip("h i\t   "), "h i");
    EXPECT_EQ(StringUtils::RStrip("hi\t"), "hi");
    EXPECT_EQ(StringUtils::RStrip("hi\t\n"), "hi");
    EXPECT_EQ(StringUtils::RStrip("  hi\t"), "  hi");
    
}

TEST(StringUtilsTest, Strip){
    std::string Base = "    hello   ";

    EXPECT_EQ(StringUtils::Strip(Base), "hello");
    EXPECT_EQ(StringUtils::Strip(""), "");
    EXPECT_EQ(StringUtils::Strip("\t\thi\t"), "hi");
    EXPECT_EQ(StringUtils::Strip("     \thi\t\n"), "hi");
    
}

TEST(StringUtilsTest, Center){
    std::string Base = "Hello!";

    EXPECT_EQ(StringUtils::Center(Base, 10, '#'), "##Hello!##");
    EXPECT_EQ(StringUtils::Center(Base, 20, ' '), "       Hello!       ");

}

TEST(StringUtilsTest, LJust){
    std::string Base = "Hello!";

    EXPECT_EQ(StringUtils::LJust(Base, 10, '#'), "Hello!####");
    EXPECT_EQ(StringUtils::LJust(Base, 20, ' '), "Hello!              ");
    
}

TEST(StringUtilsTest, RJust){
    std::string Base = "Hello!";

    EXPECT_EQ(StringUtils::RJust(Base, 10, '#'), "####Hello!");
    EXPECT_EQ(StringUtils::RJust(Base, 20, ' '), "              Hello!");
    
}

TEST(StringUtilsTest, Replace){
    
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
