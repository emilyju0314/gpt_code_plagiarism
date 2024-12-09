#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> chocolates;
vector<vector<long long>> dp;

void dfs(int u, int parent) {
    dp[u][0] = chocolates[u];
    dp[u][1] = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;

        dfs(v, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    chocolates.resize(n + 1);
    dp.resize(n + 1, vector<long long>(2));

    for (int i = 1; i <= n; i++) {
        cin >> chocolates[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}