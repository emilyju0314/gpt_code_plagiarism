#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

int n, dp[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p) {
    dp[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] += dp[v];
    }
}

int solve(int u, int p) {
    int ans = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        ans = max(ans, dp[v] * (n - dp[v]));
        ans = max(ans, solve(v, u));
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << solve(1, 0) << endl;

    return 0;
}