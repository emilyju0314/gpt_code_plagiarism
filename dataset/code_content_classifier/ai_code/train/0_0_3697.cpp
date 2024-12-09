#include <iostream>

int main() {
    int r, g, b;
    std::cin >> r >> g >> b;

    int totalTime = 0;

    while (r > 0 || g > 0 || b > 0) {
        if (r >= 2) {
            r -= 2;
            totalTime = std::max(totalTime, 30);
        } else {
            totalTime = std::max(totalTime, 30 + r);
            r = 0;
        }

        if (g >= 2) {
            g -= 2;
            totalTime = std::max(totalTime, 31);
        } else {
            totalTime = std::max(totalTime, 31 + g);
            g = 0;
        }

        if (b >= 2) {
            b -= 2;
            totalTime = std::max(totalTime, 32);
        } else {
            totalTime = std::max(totalTime, 32 + b);
            b = 0;
        }
    }

    std::cout << totalTime << std::endl;

    return 0;
}