#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        long long k;
        std::cin >> n >> k;

        long long total_ops = (1LL << n) - 1;
        if (k > total_ops) {
            std::cout << "NO\n";
        } else {
            long long res = (k - 1) % 2 == 0 ? std::log2(k) : -1;
            std::cout << "YES " << res << "\n";
        }
    }

    return 0;
}