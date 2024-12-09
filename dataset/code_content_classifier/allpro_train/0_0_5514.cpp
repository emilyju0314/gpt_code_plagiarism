#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    
    string s;
    cin >> s;
    
    vector<int> dp(x + 1);
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= x; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    
    int len_s = s.length();
    
    vector<int> f(len_s + 1, 0);
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < len_s; j++) {
            if (s[j] == '0') {
                f[j] = (1LL * f[j] * dp[i] + 1LL * f[j + 1] * dp[i - 1]) % MOD;
            } else {
                f[j] = 1LL * f[j + 1] * dp[i] % MOD;
            }
        }
    }
    
    cout << f[0] << endl;
    
    return 0;
}