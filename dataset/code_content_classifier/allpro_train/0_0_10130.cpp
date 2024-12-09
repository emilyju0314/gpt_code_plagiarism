#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    std::string output = "";
    for (char c : input) {
        output += std::string(c - 33, '+') + ". ";
    }

    std::cout << output << std::endl;

    return 0;
}