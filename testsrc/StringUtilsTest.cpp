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
    
}

TEST(StringUtilsTest, RStrip){
    
}

TEST(StringUtilsTest, Strip){
    
}

TEST(StringUtilsTest, Center){
    
}

TEST(StringUtilsTest, LJust){
    
}

TEST(StringUtilsTest, RJust){
    
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
