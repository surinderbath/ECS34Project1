#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string Base = "Hello";

    EXPECT_EQ(StringUtils::Slice(Base,0), "Hello");
    EXPECT_EQ(StringUtils::Slice(Base,1), "ello");
    EXPECT_EQ(StringUtils::Slice(Base,1,3), "el");
    EXPECT_EQ(StringUtils::Slice(Base,0,-2), "Hel");
    EXPECT_EQ(StringUtils::Slice(Base,0,-5), "");
}

TEST(StringUtilsTest, Capitalize){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Capitalize(Base),"Hello");
    EXPECT_EQ(StringUtils::Capitalize(std::string()),"");
    EXPECT_EQ(StringUtils::Capitalize(" hello")," hello");
    EXPECT_EQ(StringUtils::Capitalize("HELLO"),"Hello");
}

TEST(StringUtilsTest, Upper){
    std::string Base = "hello";

    EXPECT_EQ(StringUtils::Upper(Base), "HELLO");
    EXPECT_EQ(StringUtils::Upper("hello world!"), "HELLO WORLD!");
    EXPECT_EQ(StringUtils::Upper("\thello"), "\tHELLO");
}

TEST(StringUtilsTest, Lower){
    std::string Base = "HELLO";

    EXPECT_EQ(StringUtils::Lower(Base), "hello");
    EXPECT_EQ(StringUtils::Lower("Hello"), "hello");
    EXPECT_EQ(StringUtils::Lower("Hello World!"), "hello world!");
    
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
    EXPECT_EQ(StringUtils::Center(Base, 11, '#'), "##Hello!###");
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
    std::string Base = "Hello cold";

    EXPECT_EQ(StringUtils::Replace(Base, "cold", "World"), "Hello World");
    EXPECT_EQ(StringUtils::Replace("I like apples", "like", "hate"), "I hate apples");

}

TEST(StringUtilsTest, Split){
    std::string Base = "Hello,I am cold,We are tired";
    std::vector<std::string> v = {"Hello", "I am cold", "We are tired"};
    std::vector<std::string> w = {"apples", "bananas", "mangos"};
    std::vector<std::string> x = {"Hello", "are", "you", "okay"};
    std::vector<std::string> y = {"Hello", "are", "you", "okay", ""};


    EXPECT_EQ(StringUtils::Split(Base, ","), v);
    EXPECT_EQ(StringUtils::Split("Hello\tare you okay"), x);
    EXPECT_EQ(StringUtils::Split("Hello are you okay "), y);
    EXPECT_EQ(StringUtils::Split("apples#bananas#mangos", "#"), w);

}

TEST(StringUtilsTest, Join){
    std::vector<std::string> Base = {"Hello", "I am cold", "We are tired"};
    std::vector<std::string> w = {"apples", "bananas", "mangos"};

    EXPECT_EQ(StringUtils::Join(",", Base), "Hello,I am cold,We are tired");
    EXPECT_EQ(StringUtils::Join("#", Base), "Hello#I am cold#We are tired");
    EXPECT_EQ(StringUtils::Join("##", Base), "Hello##I am cold##We are tired");
    EXPECT_EQ(StringUtils::Join(",", w), "apples,bananas,mangos");

}

TEST(StringUtilsTest, ExpandTabs){
    std::string Base = "Hi\tcold";

     EXPECT_EQ(StringUtils::ExpandTabs(Base, 4), "Hi  cold");
     EXPECT_EQ(StringUtils::ExpandTabs(Base, 5), "Hi   cold");
     EXPECT_EQ(StringUtils::ExpandTabs("pc\tat", 7), "pc     at");
}

TEST(StringUtilsTest, EditDistance){
    
    EXPECT_EQ(StringUtils::EditDistance("kitten", "sitting", true), 3);
    EXPECT_EQ(StringUtils::EditDistance("uniformed", "uninformed", true), 1);
    EXPECT_EQ(StringUtils::EditDistance("ABCD", "abcd", false), 4);
    EXPECT_EQ(StringUtils::EditDistance("ABCD", "abcd", true), 0);
    EXPECT_EQ(StringUtils::EditDistance("ABCD", "", true), 4);
    EXPECT_EQ(StringUtils::EditDistance("", "abcd", true), 4);
    EXPECT_EQ(StringUtils::EditDistance("Abcd", "abcd", true), 0);

    
}
