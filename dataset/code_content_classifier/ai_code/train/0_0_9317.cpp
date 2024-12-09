#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> colors;
vector<int> path;

void dfs(int node, int parent) {
    // Change color of current node
    colors[node] *= -1;
    path.push_back(node + 1);

    // Traverse all the children of the current node
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            path.push_back(node + 1); // Return to the current node
        }
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n);
    colors.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> colors[i];
        colors[i] = (colors[i] == 1) ? 1 : -1;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 0-based indexing
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1); // Start DFS traversal from node 1

    // Output the path of visited nodes' indexes
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }

    return 0;
}