#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1073741824;

int d(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            result++;
        }
    }
    return result;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<vector<int>>> dp(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, 1)));

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                dp[i][j][k] = (dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1] - dp[i-1][j-1][k] - dp[i-1][j][k-1] - dp[i][j-1][k-1] + dp[i-1][j-1][k-1] + MOD) % MOD;
            }
        }
    }

    cout << dp[a][b][c] << endl;

    return 0;
}