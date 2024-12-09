#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int parent;
    int ci;
    vector<int> children;
};

vector<Node> tree;
vector<int> values;

void dfs(int node) {
    values.push_back(node + 1);
    vector<int> child_vals;

    for (int child : tree[node].children) {
        dfs(child);
        child_vals.push_back(values[child]);
    }

    sort(child_vals.begin(), child_vals.end());

    int cnt = 0;
    for (int child : tree[node].children) {
        values[child] = child_vals[cnt];
        cnt++;
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n);
    for (int i = 0; i < n; i++) {
        int p, ci;
        cin >> p >> ci;
        tree[i].parent = p;
        tree[i].ci = ci;

        if (p != 0) {
            tree[p - 1].children.push_back(i);
        }
    }

    dfs(0);

    cout << "YES" << endl;
    for (int val : values) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}