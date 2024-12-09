#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<long long> dp(n + 1);
        dp[0] = 1;

        int pd = 0;
        for (int i = 0; i < n; i++) {
            pd += a[i];
            pd %= MOD;
            
            for (int j = (i + 1) / 2; j >= 0; j--) {
                dp[j + 1] += dp[j];
                dp[j + 1] %= MOD;
            }
        }

        long long ans = 0;
        for (int i = 1; i <= n / 2; i++) {
            ans += dp[i];
            ans %= MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}