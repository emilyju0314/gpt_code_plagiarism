#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;

int dfs(int v, int p) {
    subtree_size[v] = 1;
    for(int u : adj[v]) {
        if(u != p) {
            subtree_size[v] += dfs(u, v);
        }
    }
    return subtree_size[v];
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    subtree_size.assign(n+1, 0);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int even_subtrees = 0;
        for(int u : adj[i]) {
            if(subtree_size[u] % 2 == 0) {
                even_subtrees++;
            }
        }
        if((subtree_size[i] - 1) % 2 == 0 && even_subtrees == adj[i].size()) {
            ans++;
        }
    }

    if((n - ans) % 2 == 0) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}