#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;

    vector<pair<int, int>> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i].first >> songs[i].second;
    }

    vector<vector<double>> dp(n + 1, vector<double>(T + 1, 0.0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= T; j++) {
            dp[i][j] = dp[i-1][j-1] * (1.0 - songs[i-1].first / 100.0) + (dp[i-1][max(0, j - songs[i-1].second)] + 1) * (songs[i-1].first / 100.0);
        }
    }

    cout << fixed << setprecision(9) << dp[n][T] << endl;

    return 0;
}