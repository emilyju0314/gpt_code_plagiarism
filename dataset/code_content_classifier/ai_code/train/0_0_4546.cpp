#include <iostream>
#include <string>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n, h, w;
    std::cin >> n >> h >> w;

    std::string pattern;
    std::cin >> pattern;

    std::vector<long long> dp(n, 0);
    std::vector<long long> sum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        if (pattern[i] == 'U' || pattern[i] == 'D') {
            dp[i] = 2 * h;
        } else {
            dp[i] = 2 * w;
        }
    }

    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] + dp[i - 1]) % MOD;
    }

    long long result = 0;
    for (int i = 0; i < h; i++) {
        long long moves = sum[n];
        if (pattern[0] == 'U') {
            moves -= i * 2;
        } else if (pattern[0] == 'D') {
            moves -= (h - 1 - i) * 2;
        }

        if (moves >= MOD) {
            std::cout << -1 << std::endl;
            return 0;
        }

        result = (result + moves) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}