#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int a, b;
        std::cin >> a >> b;

        int diff = std::abs(b - a);
        int moves = diff / 10;
        if(diff % 10 != 0) {
            moves++;
        }

        std::cout << moves << std::endl;
    }

    return 0;
}