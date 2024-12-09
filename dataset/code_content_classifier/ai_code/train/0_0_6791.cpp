#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    string x;
    cin >> x;
    int n = x.length();

    vector<long long> dp(n+2, 0);
    vector<long long> sum(n+2, 0);
    dp[0] = 1;
    sum[0] = 2;

    for (int i = 1; i <= n; i++) {
        if (x[i-1] == '1') {
            dp[i] = sum[i-1];
        } else {
            dp[i] = dp[i-1];
        }
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }

    long long ans1 = dp[n];
    
    long long ans2 = 2;
    for (int i = 1; i <= n; i++) {
        ans2 = (ans2 * 2) % MOD;
    }
    ans2 = (ans2 - dp[n] + MOD) % MOD;

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}