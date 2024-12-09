#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m;

struct Node {
    int value;
    vector<pair<int, int>> children; // (node, edge_value)
};

void dfs(int node, int parent, map<pair<int, int>, int>& edge_values, vector<Node>& tree) {
    for (auto child : tree[node].children) {
        int child_node = child.first;
        if (child_node != parent) {
            edge_values[{node, child_node}] = tree[child_node].value ^ tree[node].value;
            dfs(child_node, node, edge_values, tree);
        }
    }
}

bool solve() {
    cin >> n >> m;
    vector<Node> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        tree[x - 1].children.push_back({y - 1, v});
        tree[y - 1].children.push_back({x - 1, v});
    }

    map<pair<int, int>, int> edge_values;
    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        p ^= tree[a - 1].value ^ tree[b - 1].value; // XOR of the nodes' values
        int path_xor = tree[a - 1].value ^ tree[b - 1].value;
        if (__builtin_popcount(p) % 2 != p) {
            return false;
        }
        dfs(a - 1, -1, edge_values, tree);
    }

    cout << "YES" << endl;
    for (auto edge_val : edge_values) {
        cout << edge_val.first.first + 1 << " " << edge_val.first.second + 1 << " " << edge_val.second << endl;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        if (!solve()) {
            cout << "NO" << endl;
        }
    }

    return 0;
}