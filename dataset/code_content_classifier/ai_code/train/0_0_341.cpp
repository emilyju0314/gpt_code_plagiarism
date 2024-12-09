#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    dp[0][1] = dp[1][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= i; l++) {
                if (j * l > k) {
                    break;
                }
                dp[i][j] = (dp[i][j] + dp[i - l][j - 1]) % MOD;
            }
        }
    }

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + dp[n][i]) % MOD;
    }

    cout << result << endl;

    return 0;
}