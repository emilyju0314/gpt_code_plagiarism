#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> dfs_num, dfs_low, visited;
vector<pair<int, int>> bridge;
int dfs_ctr;

void find_bridge(int u, int p) {
    dfs_num[u] = dfs_low[u] = dfs_ctr++;
    visited[u] = 1;

    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        } else {
            find_bridge(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if (dfs_low[v] > dfs_num[u]) {
                bridge.push_back({u, v});
            }
        }
    }
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        adj.assign(N+1, vector<int>());
        dfs_num.assign(N+1, 0);
        dfs_low.assign(N+1, 0);
        visited.assign(N+1, 0);
        bridge.clear();
        dfs_ctr = 0;

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        find_bridge(1, -1);

        cout << bridge.size() << endl;
    }

    return 0;
}