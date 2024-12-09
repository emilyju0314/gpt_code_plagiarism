#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> tree;
vector<double> expected_steps;

void dfs(int node, int parent) {
    int children = tree[node].size() - (parent == -1 ? 0 : 1);
    double steps = 1.0 / children;

    for (int child : tree[node]) {
        if (child != parent) {
            expected_steps[child] = expected_steps[node] + steps;
            dfs(child, node);
        }
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n);
    expected_steps.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    expected_steps[0] = 0.0;
    dfs(0, -1);

    double total_steps = 0.0;
    for (int i = 0; i < n; i++) {
        total_steps += expected_steps[i];
    }

    cout << fixed << setprecision(9) << total_steps << endl;

    return 0;
}