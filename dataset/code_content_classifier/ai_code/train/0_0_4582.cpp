#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t, k;
vector<vector<pair<int, int>>> adj;
vector<int> bases;
vector<vector<int>> dp;

int solve(int u, int p, int rem) {
    if (dp[u][rem] != -1) {
        return dp[u][rem];
    }

    int ans = 0;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        int cost = solve(v, u, rem);
        if (bases[v]) {
            cost = min(cost, solve(v, u, rem - 1));
        }
        ans += cost + w;
    }

    return dp[u][rem] = ans;
}

int main() {
    int caseNum = 1;
    while (cin >> n >> t >> k) {
        if (n == 0 && t == 0 && k == 0) break;

        adj.assign(n, vector<pair<int, int>>());
        bases.assign(n, 0);
        dp.assign(n, vector<int>(k+1, -1));

        for (int i = 0; i < n-1; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            u--; v--;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        for (int i = 0; i < t; i++) {
            int base;
            cin >> base;
            bases[base-1] = 1;
        }

        int ans = solve(0, -1, k);
        cout << "Case " << caseNum << ": " << ans << endl;
        caseNum++;
    }

    return 0;
}