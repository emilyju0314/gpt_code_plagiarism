#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string password;
    std::cin >> password;

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;

    for (char c : password) {
        if (std::isupper(c)) {
            hasUpperCase = true;
        } else if (std::islower(c)) {
            hasLowerCase = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        }
    }

    if (password.length() >= 5 && hasUpperCase && hasLowerCase && hasDigit) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Too weak" << std::endl;
    }

    return 0;
}