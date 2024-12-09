#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> leaf_count;

void dfs(int u, int p, int dist) {
    bool is_leaf = true;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, dist + 1);
            is_leaf = false;
        }
    }
    
    if (is_leaf) {
        leaf_count[u] = dist;
    }
}

int main() {
    cin >> n >> k;
    adj.resize(n+1);
    leaf_count.resize(n+1, 0);
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, -1, 0);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (leaf_count[i] > k) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}