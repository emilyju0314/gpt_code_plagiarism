#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = a[0];

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD * (a[i-1] - 1) % MOD;
    }

    cout << dp[n] % MOD << endl;

    return 0;
}