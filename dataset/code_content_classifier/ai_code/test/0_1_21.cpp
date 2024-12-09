#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countPermutations(int n, int m, int k, int p) {
    vector<vector<int>> dp(k + 2, vector<int>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x = 1; x <= m; x++) {
                if (j - x >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= n; i++) {
        result = (result + dp[k][i]) % MOD;
    }

    return result;
}

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    int ans = countPermutations(n, m, k, p);
    cout << ans << endl;

    return 0;
}