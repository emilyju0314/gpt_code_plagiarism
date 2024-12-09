#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<bool>> black(h, vector<bool>(w, false));
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        black[r-1][c-1] = true;
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!black[i][j]) {
                if (i > 0 && !black[i-1][j]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                }
                if (j > 0 && !black[i][j-1]) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
                }
            }
        }
    }

    cout << dp[h-1][w-1] << endl;

    return 0;
}