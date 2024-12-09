#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b;
        std::cin >> a >> b;

        int diff = abs(a - b);
        int moves = diff / 2;
        
        if (diff % 2 == 1) {
            moves += 2;
        }

        std::cout << moves << std::endl;
    }

    return 0;
}