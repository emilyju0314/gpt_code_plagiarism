#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> leaves;

void dfs(int node, int depth) {
    if (adj[node].empty()) {
        leaves.push_back(depth);
    }

    for (int child : adj[node]) {
        dfs(child, depth + 1);
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(1, 0);

    sort(leaves.begin(), leaves.end());

    int min_result = leaves.back() - 1;

    int max_result;
    if (leaves.size() % 2 == 0) {
        max_result = leaves[leaves.size()/2] - 1;
    } else {
        max_result = leaves[leaves.size()/2];
    }

    cout << max_result << " " << min_result << endl;

    return 0;
}