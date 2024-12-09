#include <iostream>
#include <iomanip>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, r_b, c_b, r_d, c_d, p;
        cin >> n >> m >> r_b >> c_b >> r_d >> c_d >> p;

        double dp[n+1][m+1];
        dp[r_d][c_d] = 0;

        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (i == r_d && j == c_d) continue;

                dp[i][j] = ((1 + (1.0 - p/100) * dp[i+1][j] + (1.0 - p/100) * dp[i][j+1]) / (p/100));
            }
        }

        long long ans = (long long) (dp[r_b][c_b] + 0.5) % MOD;
        cout << ans << endl;
    }

    return 0;
}