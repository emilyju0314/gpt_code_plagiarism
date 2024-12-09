#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> carrots(n);
    for (int i = 0; i < n; i++) {
        std::cin >> carrots[i];
    }

    std::vector<int> result(n);
    for (int k = 0; k < n; k++) {
        std::vector<int> prefix_sum(n+1);
        for (int i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + carrots[i-1];
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = prefix_sum[j+1] - prefix_sum[i] - std::min(dp[i+1][j], dp[i][j-1]);
            }
        }

        result[k] = dp[0][n-1];
        std::rotate(carrots.rbegin(), carrots.rbegin() + 1, carrots.rend());
    }

    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}