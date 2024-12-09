#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> a(H, vector<int>(W));
    vector<vector<int>> dp(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }

    dp[0][0] = a[0][0];

    // Fill the first row
    for (int j = 1; j < W; j++) {
        dp[0][j] = dp[0][j - 1] + a[0][j];
    }

    // Fill the first column
    for (int i = 1; i < H; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }

    // Fill the rest of the dp matrix
    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    cout << dp[H - 1][W - 1] << endl;

    return 0;
}