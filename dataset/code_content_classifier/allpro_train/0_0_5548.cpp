#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;

int dp[10][200001];

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> digits(k);
    for (int i = 0; i < k; i++) {
        cin >> digits[i];
    }

    for (int i = 0; i < k; i++) {
        dp[digits[i]][1] = 1;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 2; j <= n; j++) {
            for (int m = 0; m < k; m++) {
                int remainder = j - digits[m];
                if (remainder >= 1) {
                    dp[i][j] = (dp[i][j] + dp[i][remainder]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= n/2; j++) {
            ans = (ans + (long long)dp[i][j] * dp[i][n/2]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}