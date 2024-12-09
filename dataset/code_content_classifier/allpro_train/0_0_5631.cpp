#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int timer = 0;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<pair<int, int>>& bridges) {
    tin[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v] == -1) {
            dfs(v, u, adj, tin, low, bridges);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
}

vector<pair<int, int>> findBridges(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<pair<int, int>> bridges;

    for (int u = 0; u < n; u++) {
        if (tin[u] == -1) {
            dfs(u, -1, adj, tin, low, bridges);
        }
    }

    return bridges;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> bridges = findBridges(adj);

    sort(bridges.begin(), bridges.end());

    for (auto bridge : bridges) {
        cout << bridge.first << " " << bridge.second << endl;
    }

    return 0;
}