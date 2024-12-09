#include <iostream>
#include <string>

int main() {
    std::string exhibit;
    std::cin >> exhibit;

    int rotations = 0;
    char currChar = 'a';

    for (char c : exhibit) {
        int clockwise = abs(currChar - c);
        int counterClockwise = 26 - abs(currChar - c);
        rotations += std::min(clockwise, counterClockwise);
        currChar = c;
    }

    std::cout << rotations << std::endl;

    return 0;
}