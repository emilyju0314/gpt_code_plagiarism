#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> dp(k+1, 1);

    for(int i = 2; i <= n; i++) {
        vector<long long> new_dp(k+1, 0);
        new_dp[1] = dp[1];
        for(int j = 2; j <= k; j++) {
            new_dp[j] = (2 * dp[j-1] + dp[j]) % MOD;
        }
        dp = new_dp;
    }

    long long ans = 0;
    for(int i = 1; i <= k; i++) {
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}