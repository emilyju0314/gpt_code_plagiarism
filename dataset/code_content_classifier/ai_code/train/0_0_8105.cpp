#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> adj;
vector<int> vis, cycle_id;
set<pair<int, int>> edges;

int timer = 1, cycle_num = 0;

void dfs(int v, int p) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (vis[u] == 0) {
            dfs(u, v);
        } else if (vis[u] == 1) {
            edges.erase({v, u});
            int cur = v;
            while (cur != u) {
                cycle_id[cur] = cycle_num;
                cur = adj[cur][0];
            }
            cycle_id[u] = cycle_num;
            cycle_num++;
        }
    }
    vis[v] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    cycle_id.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.insert({u, v});
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i, -1);
        }
    }

    int cnt = 0;
    for (auto edge : edges) {
        if (cycle_id[edge.first] == cycle_id[edge.second]) {
            cnt++;
        }
    }

    if (cycle_num != 1) {
        cout << 0 << endl;
    } else {
        cout << cnt << endl;
    }

    return 0;
}