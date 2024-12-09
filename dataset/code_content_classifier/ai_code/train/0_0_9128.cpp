#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string instructions;
    std::cin >> instructions;

    int numMoves = instructions.size();
    int numR = 0, numL = 0;
    for (char c : instructions) {
        if (c == 'R') {
            numR++;
        } else {
            numL++;
        }
    }

    if (numR == 0 || numL == 0) {
        std::cout << "1" << std::endl;
    } else {
        int minObstacles = std::min(numR, numL);
        std::cout << "1" << std::endl;
    }

    return 0;
}