#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> assignment(n);
    for (int i = 0; i < n; i++) {
        std::cin >> assignment[i];
    }

    std::vector<std::vector<long long>> dp(1 << n, std::vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 1;
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;

            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j)) && assignment[j] != i + 1) {
                    int new_mask = mask | (1 << j);
                    dp[new_mask][j] = (dp[new_mask][j] + dp[mask][i]) % MOD;
                }
            }
        }
    }

    long long answer = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        bool is_optimal = true;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i) && assignment[i] != i + 1) {
                is_optimal = false;
                break;
            }
        }
        if (is_optimal) {
            for (int i = 0; i < n; i++) {
                answer = (answer + dp[mask][i]) % MOD;
            }
        }
    }

    std::cout << answer << std::endl;

    return 0;
}