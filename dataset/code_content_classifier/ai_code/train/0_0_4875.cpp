#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<double>> prob(n, vector<double>(m));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> prob[i][j];
            prob[i][j] /= 1000.0;
        }
    }

    vector<double> dp(1 << n);
    dp[0] = 1.0;

    for(int i = 0; i < m; ++i) {
        vector<double> new_dp(1 << n);
        for(int mask = 0; mask < (1 << n); ++mask) {
            for(int j = 0; j < n; ++j) {
                if(mask & (1 << j)) continue;
                new_dp[mask | (1 << j)] = max(new_dp[mask | (1 << j)], dp[mask] * prob[j][i]);
            }
        }
        dp = new_dp;
    }

    double ans = 0;
    for(int mask = 0; mask < (1 << n); ++mask) {
        double cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) cnt += 1.0;
        }
        ans = max(ans, dp[mask] * cnt);
    }

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}