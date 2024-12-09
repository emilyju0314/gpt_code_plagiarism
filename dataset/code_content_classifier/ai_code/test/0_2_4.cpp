#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 200005;

vector<int> adj[MAXN];
vector<int> a(MAXN), dp(MAXN), sz(MAXN);

void dfs(int v, int p) {
    sz[v] = 1;
    dp[v] = a[v];
    
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
            dp[v] = (dp[v] + max(0, dp[u])) % MOD;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        
        if (t == 1) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    dfs(1, 0);
    
    int ans = 0;
    
    for (int v = 1; v <= n; v++) {
        ans = (ans + dp[v]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}