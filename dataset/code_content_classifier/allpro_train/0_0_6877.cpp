#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int r, g;
    cin >> r >> g;

    int h = 1;
    while ((h * (h + 1)) / 2 <= r + g) {
        h++;
    }
    h--;

    vector<vector<int>> dp(h + 1, vector<int>(r + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= h; i++) {
        for (int j = 0; j <= r; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= r; j++) {
        if (r + g - (h * (h + 1)) / 2 == j) {
            ans = (ans + dp[h][j]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}