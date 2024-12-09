#include <iostream>

int main() {
    int t;
    std::cin >> t; // Number of queries

    for(int i = 0; i < t; ++i) {
        long long a, b, k;
        std::cin >> a >> b >> k; // Length of jumps and number of jumps

        if (k % 2 == 0) {
            std::cout << (a - b) * (k / 2) << std::endl;
        } else {
            std::cout << (a * (k / 2 + 1)) - (b * (k / 2)) << std::endl;
        }
    }

    return 0;
}