#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int N, M;
vector<pair<int, int>> edges;
vector<vector<int>> adj;
vector<int> parent, depth, low, visited;
unordered_set<int> bridges;
int timer = 0;

void dfs(int v, int p) {
    visited[v] = 1;
    depth[v] = low[v] = timer++;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (visited[u]) {
            low[v] = min(low[v], depth[u]);
        } else {
            parent[u] = v;
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > depth[v]) {
                bridges.insert(u*N + v);
                bridges.insert(v*N + u);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    edges.resize(M);
    adj.resize(N);
    parent.resize(N, -1);
    depth.resize(N, 0);
    low.resize(N, 0);
    visited.resize(N, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (bridges.find(edges[i].first*N + edges[i].second) == bridges.end()) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}