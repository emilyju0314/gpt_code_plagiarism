#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000;

int main() {
    int w, h;

    while (true) {
        cin >> w >> h;
        
        if (w == 0 && h == 0) {
            break;
        }

        vector<vector<int>> dp(w + 1, vector<int>(h + 1, 0));

        dp[0][0] = 1;
        
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

        cout << dp[w][h] << endl;
    }

    return 0;
}