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

    vector<long long> dp(n+1);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * dp[a[i]]) % MOD;
    }

    cout << ans << endl;

    return 0;
}