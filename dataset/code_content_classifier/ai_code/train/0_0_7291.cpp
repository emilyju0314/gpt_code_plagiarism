#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<vector<Edge>> tree;
vector<long long> path_weights;

void dfs(int node, int parent, long long current_weight) {
    if (tree[node].size() == 1 && node != 1) {
        path_weights[node] = current_weight;
        return;
    }

    for (Edge& edge : tree[node]) {
        if (edge.to != parent) {
            dfs(edge.to, node, current_weight + edge.weight);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long S;
        cin >> n >> S;

        tree.assign(n + 1, vector<Edge>());
        path_weights.assign(n + 1, 0);

        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }

        dfs(1, -1, 0);

        long long moves = 0;
        for (int i = 2; i <= n; i++) {
            moves += (max(0LL, path_weights[i] - S) + 1) / 2;
        }

        cout << moves << endl;
    }

    return 0;
}