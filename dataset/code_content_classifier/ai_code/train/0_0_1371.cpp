#include <iostream>
#include <string>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    if (S.length() != T.length()) {
        std::cout << "No" << std::endl;
    } else {
        S += S; // Concatenate S with itself to consider all possible rotations
        if (S.find(T) != std::string::npos) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}