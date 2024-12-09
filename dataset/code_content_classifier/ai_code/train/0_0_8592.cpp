#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int binomialCoeff(int n, int k) {
    if (k == 0 || k == n) return 1;
    return (binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k)) % MOD;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    
    vector<int> l(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= j; k++) {
                dp[i][j] = (dp[i][j] + 1LL * binomialCoeff(m, k) * (1LL * k * (1LL * k * dp[i-1][k]) % MOD) % MOD * ((1LL * k * dp[i-1][k]) % MOD) % MOD) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int k = 1; k <= m; k++) {
        ans = (ans + dp[n][k]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}