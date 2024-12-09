#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    unordered_map<int, int> last;
    vector<int> dp(n+1);
    vector<int> pref(n+2, 1);

    for (int i = 0; i < n+1; i++) {
        cin >> a[i];
        if (last.find(a[i]) != last.end()) {
            int m = last[a[i]];
            dp[i] = pref[i] - pref[m];
            while (dp[i] < 0) {
                dp[i] += MOD;
            }
        } else {
            dp[i] = pref[i];
        }
        pref[i+1] = (pref[i] + dp[i]) % MOD;
        last[a[i]] = i;
    }

    for (int k = 1; k <= n+1; k++) {
        long long ans = 0;
        for (int i = 0; i < n+1; i++) {
            ans += dp[i];
            ans %= MOD;
            if (i >= k-1) {
                ans -= dp[i-k+1];
                if (ans < 0) {
                    ans += MOD;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}