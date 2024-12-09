#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<string>> actions(n + 1, vector<string>(m + 1, ""));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
        actions[i][0] = "DELETE " + to_string(i);
    }

    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
        actions[0][j] = "INSERT 1 " + string(1, t[j-1]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
                actions[i][j] = "KEEP " + to_string(i);
            } else {
                int insertCost = dp[i][j-1] + 1;
                int deleteCost = dp[i-1][j] + 1;
                int replaceCost = dp[i-1][j-1] + 1;

                if (insertCost <= min(deleteCost, replaceCost)) {
                    dp[i][j] = insertCost;
                    actions[i][j] = "INSERT " + to_string(i+1) + " " + string(1, t[j-1]);
                } else if (deleteCost <= min(insertCost, replaceCost)) {
                    dp[i][j] = deleteCost;
                    actions[i][j] = "DELETE " + to_string(i);
                } else {
                    dp[i][j] = replaceCost;
                    actions[i][j] = "REPLACE " + to_string(i) + " " + string(1, t[j-1]);
                }
            }
        }
    }

    cout << dp[n][m] << endl;
    int i = n, j = m;
    while (i > 0 || j > 0) {
        cout << actions[i][j] << endl;
        if (actions[i][j].substr(0, 4) == "REPL") {
            i--;
            j--;
        } else if (actions[i][j].substr(0, 4) == "INSE") {
            j--;
        } else {
            i--;
        }
    }

    return 0;
}