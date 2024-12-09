#include <iostream>
#include <vector>
using namespace std;

int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= m; l++) {
                for (int x = 0; x < n; x++) {
                    if (l + (x > i) <= m) {
                        dp[i][j + (x == i)][l + (x > i)] = (dp[i][j + (x == i)][l + (x > i)] + dp[i - 1][j][l]) % p;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = (ans + dp[n][k][i]) % p;
    }

    cout << ans << endl;

    return 0;
}