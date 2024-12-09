#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int v, int p, vector<vector<int>>& adj, set<pair<int, int>>& edges, int& cnt, vector<int>& vis, vector<int>& parent) {
    vis[v] = 1;
    parent[v] = p;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (vis[u] == 0) {
            edges.insert({min(v, u), max(v, u)});
            dfs(u, v, adj, edges, cnt, vis, parent);
        } else if (vis[u] == 1 && parent[v] != u) {
            int cur = v;
            set<pair<int, int>> cur_edges;
            cur_edges.insert({min(v, u), max(v, u)});
            while (parent[cur] != u) {
                cur_edges.insert({min(cur, parent[cur]), max(cur, parent[cur])});
                cur = parent[cur];
            }
            bool is_cycle = true;
            for (auto edge : cur_edges) {
                if (!edges.count(edge)) {
                    is_cycle = false;
                    break;
                }
            }
            if (is_cycle) cnt++;
        }
    }
    vis[v] = 2;
}

int count_cycles(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    set<pair<int, int>> edge_set;
    int cnt = 0;
    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1, -1);

    dfs(1, -1, adj, edge_set, cnt, vis, parent);

    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int cycles = count_cycles(n, edges);
    cout << cycles << endl;

    return 0;
}