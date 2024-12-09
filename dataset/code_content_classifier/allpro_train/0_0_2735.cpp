#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> roads(n+1, vector<pair<int, int>>(n+1, {-1, -1}));

    for (int i = 0; i < m; i++) {
        int v, u, t;
        cin >> v >> u >> t;
        roads[v][u] = {t, i};
    }

    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(m, -INF)));

    dp[1][0][m] = dp[1][1][m] = 0; // Starting point

    long long ans = 0;
    for (int len = 1; len <= 60; len++) {
        for (int v = 1; v <= n; v++) {
            for (int t = 0; t < 2; t++) {
                for (int i = 0; i < m; i++) {
                    if (dp[v][t][i] >= INF) continue;

                    if (dp[v][t][i] + (long long) pow(2, len) > INF) {
                        ans = -1;
                        break;
                    }

                    int next_t = 1 - t;
                    int next_i = roads[v][v].second;

                    if (next_i == -1) continue;

                    if (dp[v][t][i] + (long long) pow(2, len) <= INF) {
                        dp[v][next_t][next_i] = max(dp[v][next_t][next_i], dp[v][t][i] + (long long) pow(2, len));
                        ans = max(ans, dp[v][next_t][next_i]);
                    }
                }
            }
        }
    }

    if (ans == -1 || ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}