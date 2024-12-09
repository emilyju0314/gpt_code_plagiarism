#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 5e5 + 5;

int dp[MAXN][2]; // dp[i][0] is the maximum value when the subtree rooted at node i is not saturated, dp[i][1] when it is saturated
vector<pair<int, int>> adj[MAXN]; // adjacency list of the tree
int n, k;

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 0;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += dp[v][1] + w; // Include the children's saturated edges and weight
    }

    // dp[u][1] is the maximum value when the subtree rooted at node u is saturated
    vector<int> pref, suff;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        pref.push_back(dp[v][0] + w);
        suff.push_back(dp[v][0] + w);
    }

    for (int i = 1; i < pref.size(); ++i) {
        pref[i] = max(pref[i], pref[i-1]);
    }

    for (int i = suff.size() - 2; i >= 0; --i) {
        suff[i] = max(suff[i], suff[i+1]);
    }

    int sum = 0;
    for (int i = 0; i < pref.size(); ++i) {
        int left = i >= k ? pref[i-k] : 0;
        int right = i+1 < suf
        f.size() - k ? suff[i+1] : 0;
        dp[u][1] = max(dp[u][1], sum + left + right);
        sum += suff[i];
    }
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }

        for (int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dfs(1, 0);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }

    return 0;
}