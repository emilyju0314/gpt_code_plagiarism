#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        if (table[i][0] == '.') {
            dp[i][0] = dp[i - 1][0];
        } else {
            break;
        }
    }

    for (int j = 1; j < m; j++) {
        if (table[0][j] == '.') {
            dp[0][j] = dp[0][j - 1];
        } else {
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (table[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}