#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<char>> picture(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> picture[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && j > 0 && picture[i][j] == 'G' && picture[i-1][j] == 'R' && picture[i][j-1] == 'Y' && picture[i-1][j-1] == 'B') {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i][0], dp[i-1][0]);
    }

    for (int j = 1; j < m; j++) {
        dp[0][j] = max(dp[0][j], dp[0][j-1]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    for (int k = 0; k < q; k++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int res = 0;
        for (int i = r1-1; i < r2; i++) {
            for (int j = c1-1; j < c2; j++) {
                int len = min(min(r2-i, c2-j), dp[i][j]+1);
                res = max(res, len*len);
            }
        }

        cout << res << endl;
    }

    return 0;
}