#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u][v] = 1;
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, 0));
    dp[0][1] = 1;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;

            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) || graph[j][i] == 0) continue;
                dp[j][mask | (1 << j)] += dp[i][mask];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += dp[i][(1 << n) - 1];
    }

    cout << ans << endl;

    return 0;
}