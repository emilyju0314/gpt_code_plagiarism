#include <iostream>
#include <cmath>

int main() {
    int x, y;
    std::cin >> x >> y;

    int numSeconds = 0;
    while (x > y) {
        // Calculate the new side length after each second
        int newX = (int)ceil((double)(x - 1) / 2);
        x = newX;

        numSeconds++;
    }

    std::cout << numSeconds << std::endl;

    return 0;
}