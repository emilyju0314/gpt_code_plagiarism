#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string name;
    int k, n;
    cin >> name >> k >> n;

    vector<vector<int>> bonus(26, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        char x, y;
        int c;
        cin >> x >> y >> c;
        bonus[x - 'a'][y - 'a'] = c;
    }

    int len = name.length();
    vector<vector<int>> dp(len + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j <= k; j++) {
            int best = dp[i - 1][j] + bonus[name[i - 1] - 'a']['a'];
            for (char c = 'a'; c <= 'z'; c++) {
                if (j > 0) {
                    best = max(best, dp[i - 1][j - 1] + bonus[name[i - 1] - 'a'][c - 'a']);
                }
            }
            dp[i][j] = best;
        }
    }

    int ans = 0;
    for (int j = 0; j <= k; j++) {
        ans = max(ans, dp[len][j]);
    }

    cout << ans << endl;

    return 0;
}