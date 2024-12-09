#include <iostream>
#include <string>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    // Check if T is obtained by appending one character at the end of S
    if (T.substr(0, T.size() - 1) == S) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}