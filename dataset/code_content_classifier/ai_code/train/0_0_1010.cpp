#include <iostream>
#include <string>

int main() {
    int k;
    std::cin >> k;

    int length = 2;
    while (length * (length - 1) / 2 < k) {
        length++;
    }

    std::string result = "";
    char currentChar = 'a';
    for (int i = 0; i < length; i++) {
        result += currentChar;
        if (currentChar == 'z') {
            currentChar = 'a';
        } else {
            currentChar++;
        }
    }

    std::cout << result << std::endl;

    return 0;
}