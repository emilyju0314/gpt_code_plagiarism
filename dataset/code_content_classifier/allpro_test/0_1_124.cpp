#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int dp[2005][2005];

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        string starting, ending;
        cin >> n >> starting >> ending;

        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i < n && starting[i] == '1') {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                }
                if(j < n && ending[j] == '1') {
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
                }
                if(i < n && j < n && starting[i] != '1' && ending[j] != '1') {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                }
            }
        }

        cout << dp[n][n] << endl;
    }

    return 0;
}