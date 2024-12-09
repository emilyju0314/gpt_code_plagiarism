#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 998244353;

int countStates(string s) {
    int n = s.length();
    int dp[n];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    if (n >= 2) {
        dp[1] = s[0] == '0' && s[1] == '0';
    }

    for (int i = 2; i < n; i++) {
        if (s[i] == '0') {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
    }

    return dp[n - 1];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << countStates(s) << endl; 
    }

    return 0;
}