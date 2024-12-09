#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
vector<int> t(MAXN);
vector<int> h(MAXN);
vector<vector<long long>> dp(MAXN, vector<long long>(2));

void dfs(int u, int parent) {
    dp[u][0] = dp[u][1] = t[u];

    for (int v : adj[u]) {
        if (v == parent) continue;

        dfs(v, u);

        dp[u][0] += max(dp[v][0] - t[v], dp[v][1] + h[v] - 2);
        dp[u][1] += max(dp[v][0] - t[v], dp[v][1] + h[v] - 2);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}