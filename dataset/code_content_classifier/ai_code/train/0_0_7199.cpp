#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> labyrinth(n, vector<char>(m));
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'R') {
                continue;
            }

            if (i + 1 < n && labyrinth[i + 1][j] != 'R') {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }

            if (j + 1 < m && labyrinth[i][j + 1] != 'R') {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}