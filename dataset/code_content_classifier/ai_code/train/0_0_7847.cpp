#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> parent;
vector<int> dist;

void dfs(int v, int p) {
    parent[v] = p;
    for (auto u : adj[v]) {
        if (u.first != p) {
            dist[u.first] = dist[v] + u.second;
            dfs(u.first, v);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    parent.resize(n);
    dist.resize(n);

    for (int i = 0; i < n; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u - 1].push_back({v - 1, l});
        adj[v - 1].push_back({u - 1, l});
    }

    dfs(0, -1);

    int max_dist = -1;
    int max_node = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            max_node = i;
        }
    }

    fill(dist.begin(), dist.end(), 0);
    fill(parent.begin(), parent.end(), 0);

    dfs(max_node, -1);

    int min_inconvenience = 0;
    for (int i = 0; i < n; i++) {
        min_inconvenience = max(min_inconvenience, dist[i]);
    }

    cout << min_inconvenience << endl;

    return 0;
}