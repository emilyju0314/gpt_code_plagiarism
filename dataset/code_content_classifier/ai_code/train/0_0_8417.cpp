#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> weights;
vector<int> ans;

void dfs(int u, int par, int mx) {
    if (weights[u] > mx) {
        ans[u]++;
    }
    mx = max(mx, weights[u]);
    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u, mx);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n+1);
    weights.resize(n+1);
    ans.resize(n+1);
    
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[a] = weights[b] = i;
    }
    
    dfs(1, 0, 0);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}