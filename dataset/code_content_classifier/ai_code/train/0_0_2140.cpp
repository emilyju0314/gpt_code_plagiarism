#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> subtree_size;

int dfs(int v, int parent) {
    subtree_size[v] = 1;
    for (int u : adj[v]) {
        if (u != parent && !visited[u]) {
            subtree_size[v] += dfs(u, v);
        }
    }
    return subtree_size[v];
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    adj.resize(n + 1);
    visited.assign(n + 1, false);
    subtree_size.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(x, -1);
    long long ans = 1LL * n * (n - 1) - 1LL * subtree_size[y] * subtree_size[x];
    cout << ans;

    return 0;
}