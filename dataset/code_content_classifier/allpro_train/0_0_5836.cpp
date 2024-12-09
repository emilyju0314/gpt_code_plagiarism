#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> tree[MAXN];
vector<int> init_values(MAXN);
vector<int> goal_values(MAXN);
vector<int> operations;

void dfs(int node, int parent, int initial_value) {
    if (initial_value != goal_values[node]) {
        operations.push_back(node);
        initial_value = 1 - initial_value;
    }

    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node, initial_value);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> init_values[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> goal_values[i];
    }

    dfs(1, 0, init_values[1]);

    cout << operations.size() << endl;
    for (int node : operations) {
        cout << node << endl;
    }

    return 0;
}