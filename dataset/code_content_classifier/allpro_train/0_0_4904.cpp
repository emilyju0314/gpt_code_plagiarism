#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> depths;
vector<int> leaves;
int longestLeaf;

void dfs(int node, int parent, int depth) {
    depths[node] = depth;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node, depth + 1);
        }
    }
    if (tree[node].size() == 1) {
        leaves.push_back(node);
        if (depth > depths[longestLeaf]) {
            longestLeaf = node;
        }
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    depths.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0, 0);

    vector<pair<int, int>> operations;

    for (int leaf : leaves) {
        if (leaf != longestLeaf) {
            operations.push_back({longestLeaf, leaf});
        }
    }

    cout << depths[longestLeaf] * 2 - depths[leaves[0]] << "\n";

    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i].first << " " << operations[i].second << " " << (i == 0 ? leaves[0] : operations[i - 1].second) << "\n";
    }

    return 0;
}