#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

int main() {
    int n, k, q;
    std::cin >> n >> k >> q;

    std::vector<long long> flowers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> flowers[i];
    }

    std::sort(flowers.begin(), flowers.end());

    long long sum = 0;
    for (int i = 0; i < q; i++) {
        int new_flowers;
        std::cin >> new_flowers;

        flowers.push_back(new_flowers);
        std::sort(flowers.begin(), flowers.end());

        long long ans = 0;
        for (int j = 0; j < k; j++) {
            ans += flowers[j];
        }

        sum = (sum + ans) % MOD;
        std::cout << sum << std::endl;
    }

    return 0;
}