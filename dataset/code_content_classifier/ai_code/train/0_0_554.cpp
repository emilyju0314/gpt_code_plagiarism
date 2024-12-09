#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;

    vector<pair<int, int>> songs(n);
    for(int i = 0; i < n; i++) {
        cin >> songs[i].first >> songs[i].second;
    }

    vector<vector<double>> dp(n + 1, vector<double>(T + 1, 0.0));
    dp[0][0] = 1.0;

    for(int i = 0; i < n; i++) {
        for(int t = 0; t < T; t++) {
            dp[i + 1][t] += dp[i][t] * (100 - songs[i].first) / 100;
            dp[i + 1][t + songs[i].second] += dp[i][t] * songs[i].first / 100;
        }
    }

    double ans = 0.0;
    for(int i = 1; i <= n; i++) {
        for(int t = 0; t < T; t++) {
            ans += dp[i][t] * min(T - t, songs[i - 1].second);
        }
    }

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}