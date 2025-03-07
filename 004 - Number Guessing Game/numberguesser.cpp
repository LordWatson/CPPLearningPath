#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

/**
 *  - generates a target number between 1 and 100
 *  - feedback on how close the guess is to the target
 *  - track and displays the number of attempts upon success
 *
 * @return int returns 0 to indicate success
 */
int main() {
    // seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));
    // random target number between 1 and 100
    int target = rand() % 100 + 1;

    // indicate whether the target was guessed correctly
    bool correct = false;
    // counter for the number of guesses
    int guesses = 0;

    std::cout << "Welcome to the 'Guess the Number' game!" << std::endl;
    std::cout << "I have picked a random number between 1 and 100. Can you guess it?" << std::endl;

    while (!correct) {
        std::cout << "Enter your guess: ";
        int guess;
        // player's guess
        std::cin >> guess;
        guesses++;

        // input validation
        if (std::cin.fail()) {
            // clear the error flag
            std::cin.clear();
            // discard invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a valid number." << std::endl;

            continue;
        }

        // calculate the absolute difference between the target and the guess
        int difference = std::abs(target - guess);

        // provide feedback based on how close or far the guess is
        if (difference == 0) {
            // correct guess
            std::cout << "Correct! The magic number is " << target << "." << std::endl;
            std::cout << "You found the magic number in " << guesses << " guesses!" << std::endl;
            correct = true;
        } else {
            // how close?
            if (difference < 10) {
                std::cout << "Very close!" << std::endl;
            } else if (difference < 25) {
                std::cout << "Close, but not close enough." << std::endl;
            } else {
                std::cout << "You're far off." << std::endl;
            }

            // too high or too low
            if (guess < target) {
                std::cout << "Too low! Try again." << std::endl;
            } else {
                std::cout << "Too high! Try again." << std::endl;
            }
        }
    }

    // success
    return 0;
}