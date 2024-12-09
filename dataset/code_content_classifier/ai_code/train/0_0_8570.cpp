#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        x--; y--;
        graph[x][y] = t;
        graph[y][x] = t;
    }

    int v0, a, b, c;
    cin >> v0 >> a >> b >> c;

    vector<vector<int>> distances(n, vector<int>(n, INT_MAX));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j-1] + 1LL * graph[i][k] * ((a * dp[k][j-1] + b) % c));
            }
        }
    }

    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[i][n-1]);
    }

    cout << ans << endl;

    return 0;
}