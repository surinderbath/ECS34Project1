#include "StringUtils.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>

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
//https://cplusplus.com/forum/beginner/140760/#:~:text=string%3A%3Aerase(pos%2Clen,occupied%20by%20the%20character%20erased.
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

//https://www.geeksforgeeks.org/python-string-ljust-rjust-center/
//https://www.quora.com/How-do-you-define-an-empty-string-in-C-and-the-usage-of-const-empty-strings#:~:text=Using%20the%20default%20constructor%3A%20An,string%20to%20an%20empty%20state.
//https://stackoverflow.com/questions/12678819/how-to-copy-a-string-of-stdstring-type-in-c
std::string Center(const std::string &str, int width, char fill) noexcept{
    
    int chars_needed = width - str.length();
    std::string chars_string_front = "";
    chars_string_front.append(chars_needed/2, fill);
    std::string chars_string_back = "";
    chars_string_back.append(chars_needed - (chars_needed/2), fill);
    std::string Final = chars_string_front + str + chars_string_back;
    return Final;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{

    int chars_needed = width - str.length();
    std::string chars_string_back = "";
    chars_string_back.append(chars_needed, fill);
    std::string Final = str + chars_string_back;
    return Final;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{

    int chars_needed = width - str.length();
    std::string chars_string_front = "";
    chars_string_front.append(chars_needed, fill);
    std::string Final = chars_string_front + str;
    return Final;
}

//https://cplusplus.com/reference/string/string/replace/
//https://cplusplus.com/reference/string/string/find/
//https://www.educative.io/answers/what-is-stringnpos-in-cpp
std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    
    auto Copy = str;
    size_t found_pos = Copy.find(old);
    if (found_pos != std::string::npos){
        Copy.replace(found_pos, old.length(), rep);
    }

    return Copy;
}

//https://www.w3schools.com/python/ref_string_split.asp
//https://cplusplus.com/reference/vector/vector/push_back/
//https://cplusplus.com/reference/string/string/substr/
//https://cplusplus.com/reference/string/string/find_first_of/
std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    auto Copy = str;
    std::vector<std::string> Final = {};
    if(splt == ""){
        size_t start = 0;
        size_t end = 0;
        while ((end = str.find_first_of(" \t\n", start)) != std::string::npos) {
            Final.push_back(Copy.substr(start, end - start));
            start = end + 1;
        }
        Final.push_back(Copy.substr(start));

    } else{
        size_t pos = 0;
        for(int i = 0; i < Copy.length(); i++){
            pos = Copy.find(splt);
            if (pos != std::string::npos){
                Final.push_back(Copy.substr(0, pos));
                Copy.erase(0, pos + splt.length());
            }
        }

        Final.push_back(Copy);
    }
    return Final;
}

//https://www.educative.io/answers/how-to-iterate-through-a-vector-in-cpp
std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string Final = "";
    for(int i = 0; i < vect.size(); i++){
        Final.append(vect[i]);
        Final.append(str);
    } 
    
    Final.erase(Final.length() - str.length());
    return Final;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    std::string Final = "";
    int spaces_needed = 0;

    for(int i = 0; i < str.length(); i++){ 
        if(str[i] == '\t'){
            spaces_needed = (tabsize - (Final.length() % tabsize)); 
            for(int i = 0; i < spaces_needed; i++) { 
                Final += ' ';
            }
        } else {
            Final.append(str, i, 1);
        }
    }

    return Final;
}

//https://en.wikipedia.org/wiki/Levenshtein_distance
int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    if(ignorecase = true){
        Lower(left);
        Lower(right);
    }
    if(left.length() == 0){
        return right.length();
    }

    if(right.length() == 0){
        return left.length();
    }

    return 0;
}

};