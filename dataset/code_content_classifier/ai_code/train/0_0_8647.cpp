#include <iostream>
#include <string>
#include <sstream>

std::string toLowerCamelCase(std::string identifier) {
    for (int i = 0; i < identifier.length(); i++) {
        if (i == 0) {
            identifier[i] = tolower(identifier[i]);
        } else if (identifier[i] == '_') {
            // Capitalize the next letter
            identifier[i + 1] = toupper(identifier[i + 1]);
            // Remove the underscore
            identifier.erase(i, 1);
        }
    }
    return identifier;
}

std::string toUpperCamelCase(std::string identifier) {
    for (int i = 0; i < identifier.length(); i++) {
        if (identifier[i] == '_') {
            // Capitalize the next letter
            identifier[i + 1] = toupper(identifier[i + 1]);
            // Remove the underscore
            identifier.erase(i, 1);
        }
    }
    return identifier;
}

std::string toUnderscore(std::string identifier) {
    for (int i = 0; i < identifier.length(); i++) {
        if (isupper(identifier[i])) {
            // Convert uppercase letter to lowercase
            identifier[i] = tolower(identifier[i]);
            // Insert an underscore before the letter
            identifier.insert(i, "_");
            i++; // Skip the inserted underscore
        }
    }
    return identifier;
}

int main() {
    std::string identifier;
    char type;

    while (true) {
        std::cin >> identifier >> type;

        if (type == 'X') {
            break;
        }

        if (type == 'U') {
            std::cout << toUpperCamelCase(identifier) << std::endl;
        } else if (type == 'L') {
            std::cout << toLowerCamelCase(identifier) << std::endl;
        } else if (type == 'D') {
            std::cout << toUnderscore(identifier) << std::endl;
        }
    }

    return 0;
}