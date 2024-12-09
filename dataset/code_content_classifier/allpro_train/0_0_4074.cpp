#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> tree;
vector<double> prob;

void dfs(int curr, int parent, double p) {
    int num_children = (parent == -1) ? tree[curr].size() : tree[curr].size() - 1;
    if (num_children == 0) {
        prob[curr] += p;
        return;
    }

    for (int child : tree[curr]) {
        if (child == parent) continue;
        dfs(child, curr, p / num_children);
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    prob.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1, 1.0);

    cout << setprecision(10) << fixed;
    for (int i = 1; i <= n; i++) {
        cout << prob[i] << endl;
    }

    return 0;
}