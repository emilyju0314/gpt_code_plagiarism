#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 998244353;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> dolls(n);
    for (int i = 0; i < n; i++) {
        std::cin >> dolls[i];
    }

    std::vector<int> count(m + 1, 0);
    for (int mask = 0; mask < (1 << n); mask++) {
        int xor_sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                xor_sum ^= dolls[i];
            }
        }
        int set_bits = countSetBits(xor_sum);
        count[set_bits]++;
    }

    for (int i = 0; i <= m; i++) {
        std::cout << count[i] << " ";
        count[i] %= MOD;
    }

    return 0;
}