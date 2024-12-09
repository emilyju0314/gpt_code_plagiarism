#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j-1] * (i-j) + dp[i-1][j] * max(0, a[i-1] >= 2 * a[j-1])) % MOD;
        }
    }

    long long ans = 0;
    for (int j = 0; j <= n; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}