#include <iostream>

// Function that sums multiple arguments using recursion
template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Ts>
T sum(T first, Ts... rest) {
    return first + sum(rest...); // recursive call to sum the remaining arguments
}

int main() {
    int result = sum(1, 2, 3, 4, 5);
    std::cout << "Sum: " << result << '\n'; // Output: Sum: 15
    return 0;
}
