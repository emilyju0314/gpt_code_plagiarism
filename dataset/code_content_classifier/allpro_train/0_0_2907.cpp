#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int neighbor, cost;
};

vector<vector<Edge>> tree;
vector<int> maxCost;

void dfs(int node, int parent) {
    for (Edge& edge : tree[node]) {
        if (edge.neighbor != parent) {
            dfs(edge.neighbor, node);
            maxCost[node] = max(maxCost[node], maxCost[edge.neighbor] + edge.cost);
        }
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n);
    maxCost.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});
    }

    dfs(0, -1);

    cout << maxCost[0] << endl;

    return 0;
}