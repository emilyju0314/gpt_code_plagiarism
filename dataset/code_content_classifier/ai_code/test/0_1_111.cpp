#include <iostream>
#include <vector>
#include <cmath>
#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(4010, 0));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int last_mex = 0; last_mex <= 4000; last_mex++) {
            if(dp[i][last_mex] == 0) continue;

            for(int j = 0; j <= n; j++) {
                int new_mex = max(0, max(last_mex, b[i]) - k);
                dp[i+1][new_mex] += dp[i][last_mex]; 
            }
        }

        for(int j = 1; j <= 4000; j++) {
            dp[i+1][j] += dp[i+1][j-1];
        }
    }

    long long ans = dp[n][4000] % MOD;
    cout << ans << endl;

    return 0;
}