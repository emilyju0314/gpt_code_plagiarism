#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree_sizes;
vector<int> max_mex_values;

void dfs(int u, int parent) {
    subtree_sizes[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            subtree_sizes[u] += subtree_sizes[v];
            max_mex_values.push_back(subtree_sizes[v] * (adj.size() - subtree_sizes[v]));
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    subtree_sizes.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    sort(max_mex_values.rbegin(), max_mex_values.rend());

    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += 1LL * i * max_mex_values[i];
    }

    cout << ans << endl;

    return 0;
}