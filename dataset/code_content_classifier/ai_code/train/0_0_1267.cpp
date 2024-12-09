#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    // Extracting the digits from the input
    std::string digits = input.substr(1);

    // Converting the digits string to an integer
    int result = std::stoi(digits);

    // Output the result
    std::cout << result << std::endl;

    return 0;
}