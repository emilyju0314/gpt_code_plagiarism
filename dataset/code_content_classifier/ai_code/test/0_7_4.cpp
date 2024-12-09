#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> a, dp, dp_k;

void dfs(int u, int parent) {
    dp[u] = a[u];
    dp_k[u] = 0;
    
    for (auto [v, c] : adj[u]) {
        if (v == parent) continue;
        
        dfs(v, u);
        
        dp[u] = (dp[u] + dp[v]) % MOD;
        
        if (c == 1) {
            dp_k[u] = (dp_k[u] + dp_k[v]) % MOD;
            dp_k[u] = (dp_k[u] + (dp[v] * a[u]) % MOD) % MOD;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    
    dp.resize(n);
    dp_k.resize(n);
    
    dfs(0, -1);
    
    int total = 0;
    for (int i = 0; i < n; i++) {
        total = (total + dp[i]) % MOD;
    }
    
    if (k == 0) {
        cout << total << endl;
    } else {
        int res = 0;
        for (int i = 0; i < n; i++) {
            int cur = dp_k[i];
            for (auto [v, c] : adj[i]) {
                if (c == 0) {
                    cur = (cur + dp_k[v]) % MOD;
                    cur = (cur + (dp[v] * a[i]) % MOD) % MOD;
                }
            }
            res = max(res, cur);
        }
        cout << (total + res) % MOD << endl;
    }
}

int main() {
    solve();
    
    return 0;
}