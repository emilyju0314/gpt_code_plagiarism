#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> traps(n);
    for (int i = 0; i < n; i++) {
        cin >> traps[i];
    }

    vector<vector<int>> corridors(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        corridors[u].push_back(v);
        corridors[v].push_back(u);
    }

    vector<vector<double>> dp(k + 1, vector<double>(n));

    dp[k][0] = 1.0;

    for (int i = k; i > 0; i--) {
        for (int u = 0; u < n; u++) {
            if (traps[u] == 1) {
                continue;
            }
            double p = dp[i][u] / corridors[u].size();
            for (int v : corridors[u]) {
                dp[i - 1][v] += p;
            }
        }
    }

    double totalProb = 0;
    for (int i = 1; i <= k; i++) {
        totalProb += dp[i][n - 1];
    }

    cout << fixed << setprecision(10) << totalProb << endl;

    return 0;
}