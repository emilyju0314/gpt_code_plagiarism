#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);

    bool spaceFlag = false;
    for (char c : text) {
        if (c == ' ' || c == '.' || c == ',' || c == '!' || c == '?') {
            spaceFlag = true;
        } else if (std::isalpha(c) && spaceFlag) {
            std::cout << ' ';
            spaceFlag = false;
        }
        
        std::cout << c;
    }

    return 0;
}