#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int N, L;
    std::cin >> N >> L;

    std::vector<int> x(N), a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(L + 1, std::vector<int>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] %= MOD;
        }
    }

    int ans = 1;
    for (int i = 0; i < N; i++) {
        int len = a[i] - (x[i] - x[i - 1]);
        if (len < 0) {
            len = 0;
        }
        ans *= dp[len][1];
        ans %= MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}