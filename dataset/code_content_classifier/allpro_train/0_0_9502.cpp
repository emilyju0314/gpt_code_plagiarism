#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(2*n, 0));
    dp[0][1] = 2;

    for (int i = 1; i < n; i++) {
        dp[i][1] = 2; // Number of ways to form a simple path of length 1 is always 2
        for (int j = 2; j < 2*n; j++) {
            for (int k = 0; k < i; k++) {
                dp[i][j] = (dp[i][j] + 1LL * dp[k][j-1] * a[i-1] % MOD) % MOD;
            }
        }
    }

    for (int k = 1; k <= 2*n - 2; k++) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + dp[i][k]) % MOD;
        }
        cout << result << " ";
    }

    return 0;
}