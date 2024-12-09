#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    
    dp[0][s[0] - '0'] = 1;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = (dp[i][j] + ((long long)dp[i-1][j] * (s[i] - '0')) % MOD) % MOD;
            if(j > 0) {
                dp[i][j] = (dp[i][j] + (long long)dp[i-1][j-1] * (1 - (s[i] - '0')) % MOD) % MOD;
            }
        }
    }
    
    int ans = 0;
    for(int j = 0; j <= n-1; j++) {
        ans = (ans + dp[n-1][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}