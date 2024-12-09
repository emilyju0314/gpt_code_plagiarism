#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> depth;
int max_depth = 0;

void dfs(int v, int p, int d) {
    depth[v] = d;
    max_depth = max(max_depth, d);
    
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d+1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n+1);
    depth.resize(n+1);
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0, 0);
    
    long long ans = 0;
    for (int v = 1; v <= n; v++) {
        ans += (long long)depth[v] * max_depth;
    }
    
    cout << ans << endl;
    
    return 0;
}