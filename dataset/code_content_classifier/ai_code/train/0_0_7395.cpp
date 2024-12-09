#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    
    vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k && i-j >= 0; j++) {
            if(j < d) {
                dp[i][0] = (dp[i][0] + dp[i-j][0]) % MOD;
                dp[i][1] = (dp[i][1] + dp[i-j][1]) % MOD;
            } else {
                dp[i][1] = (dp[i][1] + dp[i-j][0]) % MOD;
                dp[i][1] = (dp[i][1] + dp[i-j][1]) % MOD;
            }
        }
    }
    
    cout << dp[n][1] << endl;
    
    return 0;
}