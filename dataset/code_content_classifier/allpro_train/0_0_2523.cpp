#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<long long> dp(5, 0);
    dp[0] = 1;
    
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        
        vector<long long> new_dp(5, 0);
        if (c == '0') {
            new_dp[0] = dp[1];
            new_dp[1] = (dp[0] + dp[2]) % MOD;
            new_dp[2] = (dp[1] + dp[3]) % MOD;
            new_dp[3] = (dp[2] + dp[4]) % MOD;
            new_dp[4] = dp[3];
        } else {
            new_dp[0] = 0;
            new_dp[1] = dp[0];
            new_dp[2] = dp[1];
            new_dp[3] = dp[2];
            new_dp[4] = dp[3];
        }

        dp = new_dp;

        long long ans = 0;
        for (int j = 0; j < 5; j++) {
            ans = (ans + dp[j]) % MOD;
            cout << ans << "\n";
        }
    }

    return 0;
}