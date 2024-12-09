#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    // Initialize a 3D DP array to keep track of number of ways
    std::vector<std::vector<std::vector<int>>> dp(N+1, std::vector<std::vector<int>>(N+1, std::vector<int>(N+1, 0)));
    dp[0][0][0] = 1;

    for (int k = 1; k <= N; k++) {
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                // Calculate dp[k][i][j]
                dp[k][i][j] = dp[k-1][i][j];
                if (a[k-1] == k && b[k-1] == k) {
                    continue; // If conflict with A and B's favorites, then skip
                }
                if (a[k-1] == k) {
                    dp[k][i][j] = (dp[k][i][j] + dp[k-1][i-1][j]) % MOD;
                }
                if (b[k-1] == k) {
                    dp[k][i][j] = (dp[k][i][j] + dp[k-1][i][j-1]) % MOD;
                }
                if (a[k-1] != k && b[k-1] != k) {
                    dp[k][i][j] = (dp[k][i][j] + dp[k-1][i][j]) % MOD;
                }
            }
        }
    }

    // Answer is the sum of dp[N][i][j] where i and j are both N/3
    int ans = dp[N][N/3][N/3];
    std::cout << ans << std::endl;

    return 0;
}