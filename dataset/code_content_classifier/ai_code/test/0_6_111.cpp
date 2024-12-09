#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2*k+1, vector<int>(n+1)));

    dp[0][k][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 2*k; j++) {
            for(int l = 0; l < n; l++) {
                if(dp[i-1][j][l] == 0) continue;

                for(int x = 0; x <= n; x++) {
                    if(abs(min(x, l) - b[i-1]) <= k) {
                        int new_j = max(j, abs(x - b[i-1]));
                        dp[i][new_j][x] = (dp[i][new_j][x] + dp[i-1][j][l]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= 2*k; j++) {
        for(int l = 0; l <= n; l++) {
            ans = (ans + dp[n][j][l]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}