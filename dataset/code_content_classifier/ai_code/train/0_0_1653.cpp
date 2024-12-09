#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> order;

void dfs(int node) {
    visited[node] = true;
    order.push_back(node + 1);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(0);

    for (int node : order) {
        cout << node << " ";
    }
    
    return 0;
}