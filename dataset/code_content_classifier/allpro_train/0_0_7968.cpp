#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int diameter = 0;

void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    for (auto edge : adj[node]) {
        int child = edge.first;
        int weight = edge.second;
        if (child != parent) {
            dist[child] = dist[node] + weight;
            diameter = max(diameter, dist[child]);
            dfs(child, node, adj, dist);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n);
    vector<int> dist(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(0, -1, adj, dist);

    cout << diameter << endl;

    return 0;
}