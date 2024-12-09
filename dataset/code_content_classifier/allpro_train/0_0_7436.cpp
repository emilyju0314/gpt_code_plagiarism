#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> documents(n);
    for (int i = 0; i < n; i++) {
        cin >> documents[i];
    }
    
    vector<vector<int>> dp(n/2+1, vector<int>((1<<n), 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < (1<<n); j++) {
            if (dp[i][j] == 0) continue;
            for (int k = 0; k < n; k++) {
                if (j & (1<<k)) continue;
                int cnt = 0;
                for (int l = k + 1; l < n; l++) {
                    if (j & (1<<l)) cnt++;
                }
                if (cnt <= m) {
                    dp[i+1][j|(1<<k)] += dp[i][j];
                    if (dp[i+1][j|(1<<k)] >= MOD) {
                        dp[i+1][j|(1<<k)] -= MOD;
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j < (1<<n); j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (j & (1<<i)) cnt++;
        }
        if (cnt == n/2) {
            int rev = 0;
            for (int i = 0; i < n; i++) {
                if (!(j & (1<<i))) rev |= (1<<i);
            }
            ans += 1ll * dp[n/2][j] * dp[n/2][rev] % MOD;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}