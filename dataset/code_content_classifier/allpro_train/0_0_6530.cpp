#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<int>> candies(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> candies[i][0] >> candies[i][1] >> candies[i][2];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            int eaten = 0;
            for (int k = i - 1; k >= 0; k--) {
                if (candies[k][1] < candies[i - 1][1] && candies[k][2] > candies[i - 1][2] && candies[k][0] != candies[i - 1][0]) {
                    eaten = max(eaten, dp[k][j - (candies[i - 1][1] - candies[k][1])] + 1);
                }
            }
            dp[i][j] = max(dp[i][j], eaten);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}