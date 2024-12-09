#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MOD 998244353

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    unordered_map<int, int> mp;
    for(int i = 0; i < m; i++) {
        mp[b[i]] = i;
    }

    vector<int> dp(n, 0);
    vector<int> sum(m + 1, 0);

    if(a[0] == b[0]) {
        dp[0] = 1;
        sum[1] = 1;
    }

    for(int i = 1; i < n; i++) {
        if(a[i] == b[0]) {
            dp[i] = 1;
            sum[1] = (sum[1] + 1) % MOD;
        }
        else {
            dp[i] = sum[1];
        }
        sum[1] = (sum[1] + dp[i]) % MOD;

        if(mp.count(a[i])) {
            int idx = mp[a[i]];
            if(idx > 0) {
                dp[i] = (dp[i] + sum[idx]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[m-1]) {
            ans = (ans + dp[i]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}