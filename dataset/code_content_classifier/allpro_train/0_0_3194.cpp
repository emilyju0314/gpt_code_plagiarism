#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int highestProgrammingCompetence(int n, int k, vector<int>& h, vector<int>& s, vector<int>& p, vector<int>& l) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j < l[i-1]) { // Cannot take this skill since prerequisite level is not met
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];

                for (int x = 1; x <= min(j, h[i-1]); x++) {
                    dp[i][j] = max(dp[i][j], dp[p[i-1]][j - x] + x * s[i-1]);
                }
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;

        vector<int> h(n), s(n), p(n), l(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> l[i];
        }

        cout << highestProgrammingCompetence(n, k, h, s, p, l) << endl;
    }

    return 0;
}