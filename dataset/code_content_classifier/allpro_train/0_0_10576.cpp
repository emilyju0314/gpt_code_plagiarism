#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<long long> sizes;
long long total_points = 0;

int dfs(int v) {
    visited[v] = true;
    int size = 1;

    for (int u : adj[v]) {
        if (!visited[u]) {
            size += dfs(u);
        }
    }

    sizes[v] = size;
    return size;
}

void dfs_points(int v, long long points) {
    visited[v] = true;
    total_points += points;
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs_points(u, points + sizes[1] - 2 * sizes[u]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n+1);
    visited.assign(n+1, false);
    sizes.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    visited.assign(n+1, false);
    dfs_points(1, sizes[1]);

    cout << total_points << endl;

    return 0;
}