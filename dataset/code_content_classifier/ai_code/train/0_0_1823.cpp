#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a;
        std::cin >> a;

        // Counting the number of set bits in 'a'
        int count = __builtin_popcount(a);

        // Calculating the number of non-negative solutions
        int solutions = 1 << count;

        std::cout << solutions << std::endl;
    }

    return 0;
}