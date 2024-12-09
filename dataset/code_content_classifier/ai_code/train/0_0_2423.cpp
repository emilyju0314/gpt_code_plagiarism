#include <iostream>
#include <vector>

using namespace std;

int countWays(int H, int W) {
    vector<vector<int>> dp(H + 1, vector<int>(W + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            if (i - 1 >= 0) {
                dp[i][j] += dp[i-1][j];
            }
            if (j - 2 >= 0) {
                dp[i][j] += dp[i][j-2];
            }
        }
    }

    return dp[H][W];
}

int main() {
    while (true) {
        int H, W;
        cin >> H >> W;
        if (H == 0 && W == 0) {
            break;
        }

        cout << countWays(H, W) << endl;
    }

    return 0;
}