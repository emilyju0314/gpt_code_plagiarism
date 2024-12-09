#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, x;
};

void dfs(int v, int p, vector<vector<int>>& adj_list, vector<int>& depth, vector<Edge>& edges, int& counter) {
    for (int u : adj_list[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            edges.push_back({v + 1, u + 1, counter});
            counter++;
            dfs(u, v, adj_list, depth, edges, counter);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj_list(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> depth(n, 0);
    vector<Edge> edges;
    int counter = 1;
    dfs(0, -1, adj_list, depth, edges, counter);

    for (int i = 0; i < n - 1; i++) {
        cout << edges[i].u << " " << edges[i].v << " " << edges[i].x << "\n";
    }

    return 0;
}