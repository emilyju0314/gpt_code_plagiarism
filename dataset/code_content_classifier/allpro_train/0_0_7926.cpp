#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(6, vector<int>(4, 0)));
    dp[0][0][0] = 1;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= 5; j++) {
            for(int k = 0; k <= 3; k++) {
                // Add new "I fixed a critical bug" pennant
                if(j < 5) {
                    dp[i+1][j+1][k] = (dp[i+1][j+1][k] + dp[i][j][k]) % MOD;
                }
                // Add new "I suggested a new feature" pennant
                if(k < 3) {
                    dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k]) % MOD;
                }
                // Leave the table empty
                dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= 5; i++) {
        for(int j = 0; j <= 3; j++) {
            ans = (ans + dp[n][i][j]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}