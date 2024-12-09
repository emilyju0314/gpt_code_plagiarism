#include <iostream>
#include <vector>
#include <string>

const int MOD = 1e9 + 7;

int main() {
    int n, q;
    std::cin >> n >> q;

    std::string parts;
    std::cin >> parts;

    std::vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + (parts[i] - '0');
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;

        int enjoyment = (prefix_sum[r] - prefix_sum[l - 1]) % MOD;

        int zeros = r - l + 1 - enjoyment;
        int total_ways = 1;
        for (int j = 0; j < zeros; j++) {
            total_ways = (total_ways * 2) % MOD;
        }

        std::cout << (total_ways + enjoyment) % MOD << std::endl;
    }

    return 0;
}