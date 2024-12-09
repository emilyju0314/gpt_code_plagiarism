#include <iostream>

const int MOD = 1000000007;
int dp[205][205][5][5][5][5];

int solve(int n, int k, int x1, int y1, int x2, int y2) {
    if (k == 0) {
        return 1;
    }
    if (dp[n][k][x1 + 2][y1 + 2][x2 + 2][y2 + 2] != -1) {
        return dp[n][k][x1 + 2][y1 + 2][x2 + 2][y2 + 2];
    }

    int ans = 0;

    if (x1 != 1 || y1 != 0 || x2 != 0 || y2 != 0) {
        ans = (ans + solve(n, k - 1, x1, y1, 1, 0)) % MOD;
    }
    if (x1 != -1 || y1 != 0 || x2 != 0 || y2 != 0) {
        ans = (ans + solve(n, k - 1, x1, y1, -1, 0)) % MOD;
    }
    if (x1 != 0 || y1 != 1 || x2 != 0 || y2 != 0) {
        ans = (ans + solve(n, k - 1, x1, y1, 0, 1)) % MOD;
    }
    if (x1 != 0 || y1 != -1 || x2 != 0 || y2 != 0) {
        ans = (ans + solve(n, k - 1, x1, y1, 0, -1)) % MOD;
    }

    if (n > 0) {
        if (x1 != 2 || y1 != 0 || x2 != 0 || y2 != 0) {
            ans = (ans + solve(n - 1, k - 1, x1, y1, 2, 0)) % MOD;
        }
        if (x1 != -2 || y1 != 0 || x2 != 0 || y2 != 0) {
            ans = (ans + solve(n - 1, k - 1, x1, y1, -2, 0)) % MOD;
        }
        if (x1 != 0 || y1 != 2 || x2 != 0 || y2 != 0) {
            ans = (ans + solve(n - 1, k - 1, x1, y1, 0, 2)) % MOD;
        }
        if (x1 != 0 || y1 != -2 || x2 != 0 || y2 != 0) {
            ans = (ans + solve(n - 1, k - 1, x1, y1, 0, -2)) % MOD;
        }
    }

    return dp[n][k][x1 + 2][y1 + 2][x2 + 2][y2 + 2] = ans;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    for (int i = 0; i <= 204; i++) {
        for (int j = 0; j <= 204; j++) {
            for (int x1 = 0; x1 < 5; x1++) {
                for (int y1 = 0; y1 < 5; y1++) {
                    for (int x2 = 0; x2 < 5; x2++) {
                        for (int y2 = 0; y2 < 5; y2++) {
                            dp[i][j][x1][y1][x2][y2] = -1;
                        }
                    }
                }
            }
        }
    }

    int ans = solve(n, k, 0, 0, 0, 0);
    std::cout << ans << std::endl;

    return 0;
}