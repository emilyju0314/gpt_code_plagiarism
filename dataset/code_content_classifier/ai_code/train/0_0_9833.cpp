#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int>> dp(h, vector<int>(w, 0));

    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        dp[r - 1][c - 1] = -1;
    }

    dp[0][0] = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (dp[i][j] == -1) {
                continue;
            }
            if (i > 0 && dp[i - 1][j] != -1) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if (j > 0 && dp[i][j - 1] != -1) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}