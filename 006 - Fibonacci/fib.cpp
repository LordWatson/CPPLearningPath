#include <iostream>

// Pgenerate fibonacci numbers below a target value
int main() {
    // prompt for input
    std::cout << "Enter a number: ";
    int target{};
    std::cin >> target;

    // validation
    if (!std::cin) {
        std::cerr << "Error: Input must be a valid number." << std::endl;
        return 1;
    }

    // edge cases
    if (target <= 0) {
        std::cout << "No Fibonacci numbers below " << target << "." << std::endl;
        return 0;
    }

    // store fibonacci series
    int first = 0, second = 1;

    // first fibonacci number
    std::cout << "Fibonacci numbers below " << target << ": " << first;

    // generate and print fibonacci numbers below target
    while (second < target) {
        std::cout << " " << second;

        // next fibonacci number
        int next = first + second;

        // update sequence
        first = second;
        second = next;
    }

    std::cout << std::endl;

    // success
    return 0;
}