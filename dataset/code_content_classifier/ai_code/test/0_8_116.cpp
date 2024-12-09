#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> dp(n + 1, 0);
        vector<int> last(n + 1, -1);
        dp[0] = 1;
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % MOD;
            if(last[a[i]] == -1) {
                dp[i + 1] = dp[i];
            } else {
                dp[i + 1] = (dp[i] + dp[last[a[i]]]) % MOD;
            }
            last[a[i]] = i;
        }

        cout << ans << endl;
    }

    return 0;
}