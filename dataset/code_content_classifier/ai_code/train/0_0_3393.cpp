#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> depth;
vector<int> parent;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    depth.resize(n+1);
    parent.resize(n+1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);

    int max_depth = 0;
    int max_depth_node = 0;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > max_depth) {
            max_depth = depth[i];
            max_depth_node = i;
        }
    }

    dfs(max_depth_node, 0, 0);

    vector<pair<int, int>> route;

    int current_node = max_depth_node;
    int current_time = max_depth;
    while (current_node != 0) {
        route.push_back({current_node, current_time});
        current_node = parent[current_node];
        current_time--;
    }

    for (int i = n; i >= 1; i--) {
        if (depth[i] == max_depth) {
            route.push_back({i, max_depth - 1});
        }
    }

    cout << route.size() << endl;
    for (int i = 0; i < route.size(); i++) {
        cout << route[i].first << " " << route[i].second << endl;
    }

    return 0;
}