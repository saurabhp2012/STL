#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    string a { "a" }; // Instantiating a string class object 'a' by giving a C-style string. The constructor will copy it and make it the content of the string object 'a'.

    auto b { "b"s }; // Using the string literal operator 's' to create a string object on the fly with the value "b".

    string_view c { "c" }; // Creating a string_view object 'c' that refers to the C-style string "c".

    auto d { "d"sv }; // Using the string literal operator 'sv' to create a string_view object 'd' with the value "d".

    cout << a << ", " << b << '\n'; // Printing the values of string objects 'a' and 'b'.

    cout << c << ", " << d << '\n'; // Printing the values of string_view objects 'c' and 'd'.

    cout << a + b << '\n'; // Using the '+' operator to concatenate the strings 'a' and 'b' and printing the result. operator overloaded

    cout << a + string{ c } << '\n'; // Converting the string_view 'c' to an intermediate string object and concatenating it with string 'a'. The result is printed.

    ostringstream o; // Creating an object 'o' of the ostringstream class for string stream operations.

    o << a << " " << b << " " << c << " " << d; // Inserting the values of 'a', 'b', 'c', and 'd' into the stringstream 'o'.

    auto concatenated (o.str()); // Extracting the concatenated string from the stringstream 'o' and storing it in the variable 'concatenated'.

    cout << concatenated << '\n'; // Printing the concatenated string.

    transform(begin(concatenated), end(concatenated), begin(concatenated), ::toupper); // Transforming the characters in the 'concatenated' string to uppercase using the 'transform' function and the ::toupper function.

    cout << concatenated << '\n'; // Printing the transformed uppercase string.

}
