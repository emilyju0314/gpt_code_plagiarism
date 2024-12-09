#include <iostream>
#include <string>

std::string restoreString(std::string compressed) {
    std::string restored;
    char prevChar = '\0';
    int count = 0;

    for (char c : compressed) {
        if (c == '@') {
            count = c - '0';
        } else if (std::isdigit(c)) {
            count = count * 10 + (c - '0');
        } else {
            if (count > 0) {
                for (int i = 0; i < count; ++i) {
                    restored += prevChar;
                }
                count = 0;
            }
            prevChar = c;
        }
    }

    if (count > 0) {
        for (int i = 0; i < count; ++i) {
            restored += prevChar;
        }
    }

    return restored;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << restoreString(line) << std::endl;
    }

    return 0;
}