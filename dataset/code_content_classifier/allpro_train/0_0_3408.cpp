#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> throws(n);
    for (int i = 0; i < n; i++) {
        cin >> throws[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (throws[i] == 1) {
                dp[i][j] = (dp[i + 1][j + 1] * (j + 1)) % MOD;
            } else {
                dp[i][j] = ((dp[i + 1][j] * (j + 1)) % MOD + (dp[i + 1][j + 1] * j) % MOD) % MOD;
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}