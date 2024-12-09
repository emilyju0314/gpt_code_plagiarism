#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(1010, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= words[i-1].length(); j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= words[n-1].length(); j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}