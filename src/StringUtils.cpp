#include "StringUtils.h"
#include <cctype>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{

    return str.substr(start, str.length() - start);
}

std::string Capitalize(const std::string &str) noexcept{
    
    auto Copy = str;
    Copy[0] = toupper(str[0]);
    for(size_t Index = 1; Index < Copy.length(); Index++){
        Copy[Index] = tolower(Copy[Index]);
    }
    return Copy;
}

std::string Upper(const std::string &str) noexcept{
    
    auto Copy = str;
    for(size_t Index = 0; Index < Copy.length(); Index++){
        Copy[Index] = toupper(Copy[Index]);
    }
    return Copy;
}

std::string Lower(const std::string &str) noexcept{
    
    auto Copy = str;
    for(size_t Index = 0; Index < Copy.length(); Index++){
        Copy[Index] = tolower(Copy[Index]);
    }
    return Copy;
}

//https://stackoverflow.com/questions/14544043/operand-types-are-incompatible-char-and-const-char
//fixing an error with comparisons
//https://cplusplus.com/forum/beginner/140760/#:~:text=string%3A%3Aerase(pos%2Clen,occupied%20by%20the%20character%20erased.
//figuring out how to delete the space from the string
//https://cplusplus.com/reference/cctype/isspace/
std::string LStrip(const std::string &str) noexcept{
    
    auto Copy = str;
    int count = 0;
    
    while(isspace(Copy[count])){
        count++;
    }
    Copy.erase(0,count);

    return Copy;
}

//https://cplusplus.com/reference/string/string/erase/
std::string RStrip(const std::string &str) noexcept{
    
    auto Copy = str;
    int count = Copy.length();
    
    while(isspace(Copy[count - 1])){
        count--;
    }
    Copy.erase(count, Copy.length());

    return Copy;
    
}

std::string Strip(const std::string &str) noexcept{
    
    auto Copy = LStrip(str);
    auto Final = RStrip(Copy);
    return Final;
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};