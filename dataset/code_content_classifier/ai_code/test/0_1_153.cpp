#include <iostream>
#include <vector>
#include <string>
#include <bitset>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int len = 1 << n;
    vector<int> dp(len, 0);

    for(int i = 0; i < n; i++) {
        int m = strings[i].length();
        vector<int> mask(m+1, 0);
        
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if(strings[i][j] == strings[i][k]) {
                    mask[j+1] |= (1 << k);
                }
            }
        }

        vector<int> new_dp(len, 0);
        for(int j = 0; j < len; j++) {
            new_dp[j] = dp[j];
            dp[j | (1 << i)] += dp[j];
            dp[j | (1 << i)] %= MOD;
        }

        for(int j = 0; j < m; j++) {
            for(int k = len-1; k >= 0; k--) {
                new_dp[k | mask[j+1]] += new_dp[k];
                new_dp[k | mask[j+1]] %= MOD;
            }
        }

        dp = new_dp;
    }

    int ans = 0;
    for(int i = 0; i < len; i++) {
        ans ^= (dp[i] * __builtin_popcount(i));
    }

    cout << ans << endl;

    return 0;
}