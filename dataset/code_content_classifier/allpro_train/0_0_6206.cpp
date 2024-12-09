#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int S;
    cin >> S;
    
    vector<vector<int>> dp(2001, vector<int>(2001, 0));
    dp[0][0] = 1;

    for (int i = 3; i <= S; i++) {
        for (int j = 0; j <= S; j++) {
            for (int k = 0; k <= S - j; k++) {
                dp[i + j][k + i] += dp[j][k];
                dp[i + j][k + i] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 3; i <= S; i++) {
        ans = (ans + dp[S][i]) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}