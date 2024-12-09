#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
const int MAX_M = 100000000;

int main() {
    int m;
    cin >> m;

    if(m < 7) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(2, vector<int>(10));
    for(int i = 4; i <= 7; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= m; i++) {
        for(int j = 0; j < 10; j++) {
            dp[i % 2][j] = 0;
        }

        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                if(j == 4 || j == 7) {
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][k]) % MOD;
                } else {
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 4; i <= 7; i++) {
        ans = (ans + dp[m % 2][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}