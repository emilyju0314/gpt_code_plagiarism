#include <iostream>
#include <vector>

#define MOD 1000000007

struct Point {
    int x, y;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n; i++) {
            int j = (i + len) % n;
            dp[i][j] = 0;
            for (int k = (i + 1) % n; k != j; k = (k + 1) % n) {
                if ((points[j].x - points[i].x) * (points[k].y - points[i].y) - 
                    (points[j].y - points[i].y) * (points[k].x - points[i].x) > 0) {
                    dp[i][j] += (1LL * dp[i][k] * dp[k][j]) % MOD;
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans = (ans + dp[i][i - 1]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}