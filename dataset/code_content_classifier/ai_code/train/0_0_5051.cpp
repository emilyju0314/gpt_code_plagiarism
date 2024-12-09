#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % MOD;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][k]) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}