#include <iostream>
#include <string>

using namespace std;

// constant for the error message
const string INVALID_INPUT_MESSAGE = "That's not a number.";

/**
 * @brief calculates the factorial of a number
 *
 * @param n number for which the factorial is to be calculated
 * @return int factorial of the given number
 *
 */
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    // recursive step
    return n * factorial(n - 1);
}

/**
 * @brief asks user for input and validates it
 *
 * @return int number entered by the user
 *
 * @throws terminates program with an error message from const
 *
 * @details function reads an integer from the standard input
 *          if the user enters something that cannot be parsed as an integer, an error message is displayed
            and the program exits with a non-zero status
 */
int getNumberFromUser() {
    cout << "Give me a number: ";
    int inputNumber;
    cin >> inputNumber;

    if (!cin) {
        cerr << INVALID_INPUT_MESSAGE << endl;
        // exit program with error code
        exit(1);
    }
    return inputNumber;
}

/**
 * @brief entry point
 *
 * @details
 *          1. asks the user for a number
 *          2. calculates the factorial of the input
 *          3. displays the result
 *
 * @return int returns 0 on successful execution
 */
int main() {
    // get input from user
    int inputNumber = getNumberFromUser();

    // output the factorial
    cout << "Factorial: " << factorial(inputNumber) << endl;

    // success
    return 0;
}