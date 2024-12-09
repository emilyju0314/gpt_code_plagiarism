#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int dx = std::abs(x1 - x2);
        int dy = std::abs(y1 - y2);

        if (dx == 0 || dy == 0) {
            std::cout << dx + dy << std::endl;
        } else {
            std::cout << dx + dy + 2 << std::endl;
        }
    }

    return 0;
}