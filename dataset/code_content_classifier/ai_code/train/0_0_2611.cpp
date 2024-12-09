#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    int potential = 1; // itself included
    for (int v : adj[u]) {
        if (!visited[v]) {
            potential += dfs(v, adj, visited);
        }
    }
    return potential;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_potential = 0;
    for (int i = 0; i < n; i++) {
        fill(visited.begin(), visited.end(), false);
        max_potential = max(max_potential, dfs(i, adj, visited));
    }

    cout << max_potential << endl;

    return 0;
}