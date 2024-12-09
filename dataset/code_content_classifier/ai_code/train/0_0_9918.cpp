#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        int t, q;
        cin >> t >> q;
        tasks[i] = {t, q};
    }

    vector<vector<int>> dp(n + 1, vector<int>(T + 1, 0));

    for (int i = 1; i <= n; i++) {
        int ti = tasks[i-1].first;
        int qi = tasks[i-1].second;

        for (int j = 1; j <= T; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= ti) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-ti] + qi);
            }
        }
    }

    cout << dp[n][T] << endl;

    return 0;
}