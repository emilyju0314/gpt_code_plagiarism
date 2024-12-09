#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int power(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (1LL * res * x) % MOD;
        }
        x = (1LL * x * x) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> p(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> p[i][j];
        }
    }

    std::vector<int> dp(1 << n, 0);
    dp[0] = 1;

    for (int mask = 1; mask < (1 << n); ++mask) {
        int cnt = __builtin_popcount(mask);

        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) {
                int prevMask = mask ^ (1 << j);
                for (int i = 0; i < n; ++i) {
                    if (prevMask & (1 << i) && (rand() % 100) < p[i][j]) {
                        dp[mask] = (dp[mask] + dp[prevMask]) % MOD;
                    }
                }
            }
        }
    }

    int totalMatching = dp[(1 << n) - 1];
    int totalGraphs = power(2, n);
    int invTotalGraphs = power(totalGraphs, MOD - 2);
    int solution = (1LL * totalMatching * invTotalGraphs) % MOD;

    std::cout << solution << std::endl;

    return 0;
}