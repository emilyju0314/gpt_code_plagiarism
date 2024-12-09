#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;

bool dfs(int v, int target, int parent) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (u == target && u != parent) {
            return true;
        }
        if (visited[u] == 0) {
            if (dfs(u, target, v)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long good_paths = 0;
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            fill(visited.begin(), visited.end(), 0);
            if (!dfs(i, j, -1)) {
                good_paths++;
            }
        }
    }

    cout << good_paths << endl;

    return 0;
}