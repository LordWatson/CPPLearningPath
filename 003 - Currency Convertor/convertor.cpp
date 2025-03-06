#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::cin;

// constants for currency conversion rates
const float EUR_TO_USD = 1.15;
const float USD_TO_EUR = 0.86;

/**
 * @brief converts the given amount between Euros and Dollars
 *
 * @param amount numeric value of the currency to be converted
 * @param type type of the original currency
 * @return converted value in the destination currency
 */
float convert(float amount, string type) {
    if (type == "EUR") {
        // convert from Euros to USD
        return amount * EUR_TO_USD;
    }

    // convert from USD to Euros
    return amount * USD_TO_EUR;
}

/**
 * @brief function to perform currency conversion based on user input
 *
 * @return int 0 on success, 1 on invalid input or error
 */
int main() {
    // display conversion options
    cout << "Choose conversion type: " << endl;
    cout << "1. EUR to USD" << endl;
    cout << "2. USD to EUR" << endl;

    // store the user's choice
    int choice;
    cin >> choice;

    // check for invalid input
    if (!cin) {
        cout << "Invalid input. Please enter a valid number." << endl;
        return 1;
    }

    // store currency info
    // type of currency
    string type;
    // symbol of the source currency
    string sign;
    // symbol of the target currency
    string convertedSign;
    // amount to be converted
    float amount;

    // conversion type based on selection
    switch (choice) {
        case 1:
            // "EUR to USD"
            cout << "Enter value in Euros: ";
            type = "EUR";
            sign = "€";
            convertedSign = "$";
            break;

        case 2:
            // "USD to EUR"
            cout << "Enter value in Dollars: ";
            type = "USD";
            sign = "$";
            convertedSign = "€";
            break;

        default:
            // invalid choice
            cout << "Please pick an option from the list." << endl;
            return 1;
    }

    // input amount
    cin >> amount;

    // validation
    if (!cin) {
        cout << "Invalid input. Please enter a numeric value." << endl;
        return 1;
    }

    // perform conversion and display the result
    cout << sign << amount << " is "
         << convertedSign << std::fixed << std::setprecision(2)
         << convert(amount, type) << endl;

    // success
    return 0;
}