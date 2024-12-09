#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> dp(n+1, 0);
    vector<int> pref(n+1, 0);
    
    dp[0] = 1;
    pref[0] = 1;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            for(int j = k; j <= i+1; j++) {
                dp[i+1] = (dp[i+1] + pref[max(0, i-j+1)]) % MOD;
            }
        }
        pref[i+1] = (pref[i] + dp[i+1]) % MOD;
    }

    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = (ans + dp[n-i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}