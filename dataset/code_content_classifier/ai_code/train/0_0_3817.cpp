#include <iostream>

int main() {
    int w, h, u1, d1, u2, d2;
    std::cin >> w >> h >> u1 >> d1 >> u2 >> d2;

    for (int i = h; i > 0; i--) {
        w += i; // Increase weight by current height
        if (i == d1) {
            w -= u1; // If snowball hits first stone, decrease weight by the weight of the stone
            if (w < 0) w = 0; // If weight becomes negative, set it to 0
        } else if (i == d2) {
            w -= u2; // If snowball hits second stone, decrease weight by the weight of the stone
            if (w < 0) w = 0; // If weight becomes negative, set it to 0
        }
        if (w == 0) break; // If weight becomes 0, stop the loop
    }

    std::cout << w << std::endl;

    return 0;
}