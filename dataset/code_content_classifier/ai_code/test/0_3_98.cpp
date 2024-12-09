#include <iostream>
#include <string>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string keyboard, word;
        std::cin >> keyboard >> word;

        int time = 0;
        int currPos = 0;

        for (char c : word) {
            int newPos = keyboard.find(c);
            time += std::abs(newPos - currPos);
            currPos = newPos;
        }

        std::cout << time << std::endl;
    }

    return 0;
}