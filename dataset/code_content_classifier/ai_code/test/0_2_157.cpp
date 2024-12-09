#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> ones(n+1, 0);
    for(int i = 0; i < n; i++) {
        ones[i+1] = ones[i] + (s[i] == '1');
    }

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        if(ones[i] == k) {
            dp[i] = (dp[i] + 1) % MOD;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(ones[j] - ones[i-1] == k) {
                ans = (ans + dp[i-1] * dp[n-j] % MOD) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}