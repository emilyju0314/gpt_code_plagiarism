#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int w, h;
    cin >> w >> h;

    // Initialize dp table
    vector<vector<int>> dp(w + 1, vector<int>(h + 1, 0));

    // Base case
    dp[0][0] = 1;

    // Fill up the dp table
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            if (i + 1 <= w) {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
            if (j + 1 <= h) {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
        }
    }

    // Output the result
    cout << dp[w][h] << endl;

    return 0;
}