#include <iostream>
#include <string>

bool isValidPassword(const std::string& password) {
    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;

    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
        } else if (islower(c)) {
            hasLower = true;
        } else if (isupper(c)) {
            hasUpper = true;
        }
    }

    return hasDigit && hasLower && hasUpper;
}

std::string replaceSubstring(const std::string& password) {
    int lowerPos = -1;
    int upperPos = -1;
    int digitPos = -1;

    for (int i = 0; i < password.length(); i++) {
        if (islower(password[i])) {
            lowerPos = i;
        } else if (isupper(password[i])) {
            upperPos = i;
        } else if (isdigit(password[i])) {
            digitPos = i;
        }
    }

    if (lowerPos == -1) {
        password[0] = 'a';
    } else if (upperPos == -1) {
        password[1] = 'A';
    } else if (digitPos == -1) {
        password[2] = '1';
    }

    return password;
}

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::string password;
        std::cin >> password;

        if (!isValidPassword(password)) {
            std::cout << replaceSubstring(password) << std::endl;
        } else {
            std::cout << password << std::endl;
        }
    }

    return 0;
}