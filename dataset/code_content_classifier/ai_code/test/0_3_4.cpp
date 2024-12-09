#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int n, k;
vector<vector<pair<int, int>>> adj;
vector<long long> a;
long long ans = 0;

void dfs(int u, int p, int c, int tk) {
    if (tk > k) {
        return;
    }
    
    if (p != -1) {
        c = max(c + a[u], a[u]);
        ans = (ans + c) % MOD;
    }
    
    for (pair<int, int> v : adj[u]) {
        int next = v.first;
        int color = v.second;
        
        if (next != p) {
            dfs(next, u, c - (color != a[u]), tk + (color != a[u]));
        }
    }
}

int main() {
    cin >> n >> k;
    
    adj.resize(n);
    a.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    
    dfs(0, -1, 0, 0);
    
    cout << ans << endl;
    
    return 0;
}