#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<long long> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 2; i <= n; i += 2) {
        if (s[i-1] == s[i-2]) {
            int k = (i-2)/2;
            dp[i] = (dp[i] + dp[k]) % MOD;
        }
        for (int j = 2; j <= i; j += 2) {
            if (s[i-j] != s[i-1] || s[i-j+1] != s[i]) {
                continue;
            }
            int k = (i-j-2)/2;
            dp[i] = (dp[i] + dp[j-2] * dp[k]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}