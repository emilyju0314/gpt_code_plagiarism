#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int x, y;
        std::cin >> x >> y;

        int moves = 0;
        if (x != 0 && y == 0) {
            moves = x;
        } else if (x == 0 && y != 0) {
            moves = y;
        } else {
            moves = x + y + 2;
        }

        std::cout << moves << std::endl;
    }

    return 0;
}