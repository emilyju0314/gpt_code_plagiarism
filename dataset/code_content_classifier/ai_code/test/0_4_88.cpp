#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        bool possible = false;
        int xor_result = 0;

        std::vector<int> lis(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j]) {
                    lis[i] = std::max(lis[i], lis[j] + 1);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            xor_result ^= lis[i];
        }

        if (xor_result == 0) {
            possible = true;
        }

        if (possible) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}