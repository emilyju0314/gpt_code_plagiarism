#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string start, end;
        cin >> start >> end;

        vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                if(start[i-1] == '?' && end[i-1] == '?') {
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                    if(j > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                    if(j+1 <= i) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                } else if(start[i-1] == '?') {
                    if((end[i-1] - '0') == j) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                    if(j > 0 && j-1 == (end[i-1] - '0')) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                    if(j+1 <= i && j+1 == (end[i-1] - '0')) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                } else if(end[i-1] == '?') {
                    if((start[i-1] - '0') == j) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                    if(j > 0 && j-1 == (start[i-1] - '0')) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                    if(j+1 <= i && j+1 == (start[i-1] - '0')) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                } else {
                    if((start[i-1] - '0') == j && (end[i-1] - '0') == j) dp[i][j] = dp[i-1][j];
                }
            }
        }

        long long ans = 0;
        for(int j = 0; j <= n; j++) {
            ans = (ans + dp[n][j]) % MOD;
        }
        
        cout << ans << endl;
    }

    return 0;
}