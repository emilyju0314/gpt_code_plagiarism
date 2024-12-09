#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<char>> matrix(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = s[j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, INF)));
    dp[0][0][0] = 0;

    for (int ck = 0; ck <= k; ck++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    dp[i][j][ck] = min(dp[i][j][ck], dp[i-1][j][ck] + (matrix[i][j] != 'a'));
                }
                if (j > 0) {
                    dp[i][j][ck] = min(dp[i][j][ck], dp[i][j-1][ck] + (matrix[i][j] != 'a'));
                }
                if (ck > 0) {
                    if (i > 0) {
                        dp[i][j][ck] = min(dp[i][j][ck], dp[i-1][j][ck-1] + (matrix[i][j] != 'a'));
                    }
                    if (j > 0) {
                        dp[i][j][ck] = min(dp[i][j][ck], dp[i][j-1][ck-1] + (matrix[i][j] != 'a'));
                    }
                }
            }
        }
    }

    int row = n-1, col = n-1, changesLeft = k;
    string path = "";
    while (row > 0 || col > 0) {
        if (row > 0 && dp[row][col][changesLeft] == dp[row-1][col][changesLeft] + (matrix[row][col] != 'a')) {
            path = matrix[row][col] + path;
            row--;
        } else {
            path = matrix[row][col] + path;
            col--;
        }
        if (matrix[row][col] != 'a') {
            changesLeft--;
        }
    }
    path = matrix[0][0] + path;

    cout << path << endl;

    return 0;
}