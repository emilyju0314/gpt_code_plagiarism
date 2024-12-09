#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    std::string output;
    for (char c : input) {
        if (output.empty() || output.back() != c) {
            output.push_back(c);
        } else {
            output.pop_back();
        }
    }

    std::cout << output << std::endl;

    return 0;
}