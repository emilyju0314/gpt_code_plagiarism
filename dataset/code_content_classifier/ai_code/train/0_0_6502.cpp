#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 998244353;

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cin >> m;
    std::vector<std::vector<int>> colored(n, std::vector<int>(a[n-1] + 1, 0));
    for (int i = 0; i < m; i++) {
        int x, y, c;
        std::cin >> x >> y >> c;
        colored[x-1][y] = c;
    }

    std::vector<std::vector<int>> f(3, std::vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> f[i][j];
        }
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(a[n-1] + 1, 0));
    dp[0][1] = dp[0][2] = dp[0][3] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            for (int k = 1; k <= 3; k++) {
                if (colored[i][j] == 0 || colored[i][j] == k) {
                    for (int l = 1; l <= 3; l++) {
                        if (f[k-1][l-1]) {
                            int nj = j + l;
                            if (nj <= a[i-1]) {
                                dp[i][nj] = (dp[i][nj] + dp[i-1][j]) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= a[n-1]; i++) {
        ans = (ans + dp[n-1][i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}