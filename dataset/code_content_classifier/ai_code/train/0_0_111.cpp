#include <iostream>
#include <string>

int main() {
    std::string input;
    int index;
    std::getline(std::cin, input);
    std::cin >> index;

    for (char& c : input) {
        if (c >= 'a' && c <= 'z') {
            if (c - 'a' + index < 26) {
                c = c + index;
            } else {
                c = c + index - 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            if (c - 'A' + index < 26) {
                c = c + index;
            } else {
                c = c + index - 26;
            }
        }
    }

    std::cout << input << std::endl;

    return 0;
}