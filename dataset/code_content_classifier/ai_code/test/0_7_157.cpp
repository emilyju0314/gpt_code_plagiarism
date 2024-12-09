#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MOD 998244353
using namespace std;

int power(int a, int b) {
    int res = 1;
    while (b != 0) {
        if (b % 2 == 1) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    if (k == 0) {
        ans = 1;
    } else if (k == 1) {
        ans = power(2, n);
    } else {
        vector<int> cnt;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cur++;
            } else {
                cnt.push_back(cur);
                cur = 0;
            }
        }
        if (cur > 0) {
            cnt.push_back(cur);
        }
        
        int t = cnt.size();
        int dp[t + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        for (int i = 0; i < t; i++) {
            int l = cnt[i];
            for (int j = 0; j <= n; j++) {
                for (int r = 0; r <= min(j, l); r++) {
                    dp[i + 1][j] = (dp[i + 1][j] + (1LL * dp[i][j - r] * power(2, r))) % MOD;
                }
            }
        }
        
        ans = dp[t][k];
    }
    
    cout << ans << endl;
    
    return 0;
}