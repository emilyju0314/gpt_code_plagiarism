#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] = min(graph[u][v], c);
        graph[v][u] = min(graph[v][u], c);
    }

    vector<vector<vector<int>>> dp(k, vector<vector<int>>(n+1, vector<int>(n+1, INF)));
    dp[0][1][1] = 0;

    for (int i = 1; i < k; i++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                for (int j = 1; j <= n; j++) {
                    if (u == v || u == j || v == j) continue;
                    dp[i][v][j] = min(dp[i][v][j], dp[i-1][u][v] + graph[v][j]);
                }
            }
        }
    }

    int ans = INF;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            ans = min(ans, dp[k-1][u][v]);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}