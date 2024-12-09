#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    vector<int> children;
};

vector<Node> tree;
vector<int> initial_values;

void dfs(int node, int parent, int diff) {
    tree[node].val += diff;
    for(int child : tree[node].children) {
        if(child != parent) {
            dfs(child, node, -diff);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    tree.resize(n);
    initial_values.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> initial_values[i];
        tree[i].val = initial_values[i];
    }

    for(int i = 0; i < n-1; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        tree[v].children.push_back(u);
        tree[u].children.push_back(v);
    }

    for(int i = 0; i < m; i++) {
        int type, x, val;
        cin >> type >> x;

        if(type == 1) {
            cin >> val;
            x--;
            dfs(x, -1, val);
        } else {
            x--;
            cout << tree[x].val << endl;
        }
    }

    return 0;
}