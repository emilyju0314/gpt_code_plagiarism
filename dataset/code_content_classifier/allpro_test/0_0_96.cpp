#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1)); // dp[i][j] represents the number of ways to choose health points for i heroes with maximum health j

    dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= x; j++) {
            for(int k = 1; k < j; k++) {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    long long ans = 0;
    for(int i = 1; i <= x; i++) {
        ans += dp[n][i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}