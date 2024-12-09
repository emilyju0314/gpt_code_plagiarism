#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 5;
vector<int> adj[MAXN];
int dp[MAXN];
int n;

void dfs(int u, int p) {
    dp[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    return 0;
}