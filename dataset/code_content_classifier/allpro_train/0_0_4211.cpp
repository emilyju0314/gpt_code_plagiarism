#include <iostream>

int main() {
    int p, x, y;
    std::cin >> p >> x >> y;

    int s = x;
    int i = (s / 50) % 475;
    int hacks = 0;

    while (true) {
        i = (i * 96 + 42) % 475;
        if (26 + i == p) break;
    }

    while (x < y) {
        if (x + 100 <= y || (26 + i) == p) {
            x += 100;
            hacks++;
        } else {
            x -= 50;
        }
    }

    std::cout << hacks << std::endl;

    return 0;
}