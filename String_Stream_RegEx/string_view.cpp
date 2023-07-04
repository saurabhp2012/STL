// `string_view` is a lightweight non-owning, read-only view of a sequence of characters. 
//It is part of the C++ Standard Library and introduced in C++17. 
//It is designed to efficiently work with string-like data without incurring 
//the overhead of creating a separate string object or making a copy of the underlying data.

// Here are some key characteristics and features of `string_view`:

// 1. Non-owning: Unlike `string`, `string_view` does not own the underlying character sequence.
// It is a non-owning reference or view of the data, allowing you to work with existing strings or character arrays without copying the data.

// 2. Read-only view: `string_view` provides read-only access to the underlying character sequence.
// You can't modify the contents of the `string_view`. This immutability makes it suitable for scenarios where you only need to read or process the string data.

// 3. Lightweight: `string_view` is a lightweight object that typically consists of only two pointers, pointing to the beginning and end of the character sequence.
// It does not perform any memory allocations or deallocations.

// 4. Range-based operations: `string_view` supports various range-based operations,
// such as accessing individual characters, slicing the string, comparing with other `string_view` objects, and finding substrings.

// 5. Interoperability: `string_view` is designed to work seamlessly with existing string classes, like `std::string`. 
//It provides implicit conversions from `const char*`, `const std::string&`, and other string-like objects, 
//allowing you to use `string_view` in place of strings when appropriate.

// The use of `string_view` can help reduce unnecessary string copies, 
//improve performance, and provide a more flexible and efficient way to handle strings in C++ programs.
// It is particularly useful in situations where you need to pass strings to functions or algorithms
// without incurring the cost of creating and copying new string objects.

#include <iostream>
#include<string_view>

using namespace std;
void print(string_view v){
    //note: do not expect  a null terminated string 

    const auto words_begin (v.find_first_not_of(" \t\n")); // not changing the string, but the view on the string by trimming ws
    v.remove_prefix(min(words_begin,v.size())); //if npos taken care

    const auto words_end (v.find_last_not_of(" \t\n"));

    if(words_end !=string_view::npos){
        v.remove_suffix(v.size()-words_end-1);
    }
    cout<<"length: "<<v.length()<<"[ "<<v<<" ]\n";

}
int main(int argc, char* argv[]){

    print(argv[0]);
    print("a const char * array");
    print("an std::string_view literal"sv);
    print("an std::string instance"s);
    print("  \t\n foobar   \n  \t  ");
    
    char cstr[] {'a','b','c'}; // no null termination

    print(string_view(cstr, sizeof(cstr)));

}
