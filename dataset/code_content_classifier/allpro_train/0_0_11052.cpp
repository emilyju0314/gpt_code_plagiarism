#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1e9 + 7;

bool isPerfectSquare(int n) {
    int sq = sqrt(n);
    return sq * sq == n;
}

int countRightPermutations(int n, const std::vector<int>& arr) {
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                if (!isPerfectSquare(arr[i-1] * arr[k])) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
                }
            }
        }
    }

    return dp[n][n];
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int result = countRightPermutations(n, arr);
    std::cout << result << std::endl;

    return 0;
}