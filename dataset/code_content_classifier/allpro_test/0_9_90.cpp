#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int x, y;
        std::cin >> x >> y;

        if (x > y) {
            std::cout << x << std::endl;
        } else {
            std::cout << x + y << std::endl;
        }
    }

    return 0;
}