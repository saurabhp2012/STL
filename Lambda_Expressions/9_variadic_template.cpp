#include <iostream>



// Function template that prints multiple arguments
template<typename... Args>
void printArgs(Args... args) {
    ((std::cout << args << " "), ...); // fold expression to print all arguments
//will expand to (std::cout << 1 << " "), (std::cout << "hello" << " "), (std::cout << 3.14 << " ")
    std::cout << '\n';
}

int main() {
    printArgs(1, "hello", 3.14, 'a');
    return 0;
}
