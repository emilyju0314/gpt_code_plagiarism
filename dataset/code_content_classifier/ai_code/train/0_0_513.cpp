#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string text;
    std::getline(std::cin, text);

    int Q;
    std::cin >> Q;
    std::cin.ignore();

    for (int i = 0; i < Q; i++) {
        std::string pattern;
        std::getline(std::cin, pattern);

        if (text.find(pattern) != std::string::npos) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}