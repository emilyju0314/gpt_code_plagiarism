#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, x, y, d;
        std::cin >> n >> x >> y >> d;

        // Check if it's possible to reach y directly from x
        if (std::abs(y - x) % d == 0) {
            std::cout << std::abs(y - x) / d << std::endl;
        } else {
            // Calculate the number of button presses to reach y
            int min_presses = INT_MAX;

            // Check if going forward is possible
            if ((y - x) % d == 0) {
                min_presses = std::min(min_presses, (y - x) / d);
            }

            // Check if going backward is possible
            if ((x - y) % d == 0) {
                min_presses = std::min(min_presses, (x - y) / d + (x - y) % d == 0);
            }

            if (min_presses == INT_MAX) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << min_presses << std::endl;
            }
        }
    }

    return 0;
}