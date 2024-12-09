#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<vector<int>>> cars(m, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> cars[i][j][k];
            }
        }
    }

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(n, vector<int>(n, INF)));

    for (int i = 0; i < r; i++) {
        int si, ti, ki;
        cin >> si >> ti >> ki;
        si--; ti--;

        dp[i][si][ti] = 0;

        for (int k = 0; k < ki; k++) {
            vector<vector<int>> new_dp = dp[i]; // Copy existing dp table

            for (int j = 0; j < n; j++) {
                for (int u = 0; u < n; u++) {
                    for (int v = 0; v < n; v++) {
                        new_dp[u][v] = min(new_dp[u][v], dp[i][u][j] + dp[i][j][v]);
                    }
                }
           }

           dp[i] = new_dp;
        }

        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                for (int car = 0; car < m; car++) {
                    dp[i][u][v] = min(dp[i][u][v], dp[i][u][ti] + cars[car][ti][v]);
                }
            }
        }

        cout << dp[i][si][ti] << endl;
    }

    return 0;
}