#include <iostream>
#include <cmath>

int main() {
    int n, p;
    std::cin >> n >> p;

    for (int k = 0; k < 32; ++k) {
        int x = n - k*p;
        if (x >= k && __builtin_popcount(x) <= k) {
            std::cout << k << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;

    return 0;
}