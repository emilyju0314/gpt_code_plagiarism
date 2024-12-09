#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (s[i-1] == '?') {
            dp[i] = (2 * dp[i-1]) % MOD;
        } else if (s[i-1] >= '0' && s[i-1] <= '2') {
            dp[i] = dp[i-1];
        } else if (s[i-1] == '*') {
            if (i >= 2 && s[i-2] == '?') {
                dp[i] = (2 * dp[i-2]) % MOD;
            }
            if (i >= 3 && s[i-2] == '*' && s[i-3] == '?') {
                dp[i] = (dp[i] + dp[i-3]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}