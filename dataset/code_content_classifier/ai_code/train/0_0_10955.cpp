#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                prev[i][j] = {i - 1, j - 1};
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    prev[i][j] = {i - 1, j};
                } else {
                    dp[i][j] = dp[i][j - 1];
                    prev[i][j] = {i, j - 1};
                }
            }
        }
    }

    if (dp[n][m] < m) {
        cout << -1 << endl;
    } else {
        cout << dp[n][m] << endl;

        int i = n, j = m;
        vector<pair<int, int>> pieces;
        while (dp[i][j] > 0) {
            if (s[i - 1] == t[j - 1]) {
                pieces.push_back({i, j});
                i--;
                j--;
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        for (int k = pieces.size() - 1; k >= 0; k--) {
            cout << pieces[k].first << " " << pieces[k].second << endl;
        }
    }

    return 0;
}