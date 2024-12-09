#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<vector<int>>> carTimes(m, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> carTimes[i][j][k];
            }
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(r + 1, INT_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = 0;
        }
    }

    for (int round = 0; round < r; round++) {
        int s, t, k;
        cin >> s >> t >> k;
        s--;
        t--;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 1; l <= k; l++) {
                    dp[i][j][round+1] = min(dp[i][j][round+1], dp[i][j][round] + carTimes[l-1][i][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    dp[j][l][round+1] = min(dp[j][l][round+1], dp[j][i][round] + dp[i][l][round]);
                }
            }
        }

        cout << dp[s][t][round+1] << endl;
    }

    return 0;
}