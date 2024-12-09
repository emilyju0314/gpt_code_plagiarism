#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1e5+5;

int n, q;
vector<int> a[MAXN];
vector<int> adj[MAXN];
int parent[MAXN];
int energy[MAXN];
int depth[MAXN];
int dp[MAXN][20];

void dfs(int u, int par, int d) {
    parent[u] = par;
    depth[u] = d;
    
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u, d+1);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = dp[u][i];
        }
    }
    
    if (u == v) return u;
    
    for (int i = 19; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    
    return parent[u];
}

int main() {
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> energy[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0, 0);
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = parent[i];
    }
    
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            energy[u] = v;
        } else if (type == 2) {
            int l = lca(u, v);
            int sum = abs(energy[u] + energy[v]);
            int dist = abs(energy[u] - energy[v]);
            int ans = max(sum, dist);
            
            while (u != l) {
                int par = parent[u];
                int sum1 = abs(energy[par] + energy[u]);
                int dist1 = abs(energy[par] - energy[u]);
                ans += max(sum1, dist1);
                u = par;
            }
            
            while (v != l) {
                int par = parent[v];
                int sum2 = abs(energy[par] + energy[v]);
                int dist2 = abs(energy[par] - energy[v]);
                ans += max(sum2, dist2);
                v = par;
            }
            
            cout << ans << endl;
        }
    }
    
    return 0;
}