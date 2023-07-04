#include <iostream>

// Function that computes the product of multiple arguments using fold expression
template<typename... Args>
auto product(Args... args) {
    return (args * ... * 1); // fold expression to multiply all arguments
}

int main() {
    int result = product(2, 3, 4, 5);
    std::cout << "Product: " << result << '\n'; // Output: Product: 120
    return 0;
}
