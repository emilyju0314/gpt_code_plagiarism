#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    // Parsing the input string
    int a = input[0] - '0';
    int d = std::stoi(input.substr(2, input.find('e') - 2));
    int b = std::stoi(input.substr(input.find('e') + 1));

    if (b == 0) {
        // If b is 0, output the distance value as an integer
        std::cout << a;
    } else {
        // Otherwise, output the distance value in decimal form
        std::cout << a;
        int remainingDigits = b - (input.length() - 3);
        if (remainingDigits >= 0) {
            std::cout << d;
            for (int i = 0; i < remainingDigits; i++) {
                std::cout << "0";
            }
        } else {
            int decimalPos = input.length() - remainingDigits;
            for (int i = 2; i < decimalPos; i++) {
                std::cout << input[i];
            }
            std::cout << ".";
            for (int i = decimalPos; i < input.length() - 1; i++) {
                std::cout << input[i];
            }
        }
    }

    return 0;
}