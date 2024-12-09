#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<char> changes(n);
    for (int i = 0; i < n; i++) {
        cin >> changes[i];
    }

    vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        if (changes[i-1] == 'U') {
            dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % MOD;
        } else if (changes[i-1] == 'D') {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        } else {
            dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % MOD;
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;

    return 0;
}