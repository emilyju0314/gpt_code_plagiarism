#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int toNode;
    int length;
};

int n;
vector<vector<Edge>> tree;
vector<int> dp;

int dfs(int node, int parent) {
    int max_path = 0;
    for (const Edge& edge : tree[node]) {
        if (edge.toNode != parent) {
            int path_length = edge.length + dfs(edge.toNode, node);
            max_path = max(max_path, path_length);
        }
    }
    return dp[node] = max_path;
}

int main() {
    int q;
    cin >> n >> q;
    tree.resize(n);
    dp.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--, v--;  // 0-indexed nodes
        tree[u].push_back({v, l});
        tree[v].push_back({u, l});
    }

    dfs(0, -1);  // Start the dfs from node 0 (or any starting node)

    for (int i = 0; i < q; i++) {
        int xi, yi;
        cin >> xi >> yi;
        xi--;  // 0-indexed nodes
        int answer = dp[xi];
        cout << answer + yi << endl;
    }

    return 0;
}