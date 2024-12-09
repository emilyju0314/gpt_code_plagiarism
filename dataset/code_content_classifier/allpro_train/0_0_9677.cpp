#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

vector<vector<int>> adj;
vector<long long> dp1, dp2;

void dfs(int v, int p) {
    dp1[v] = dp2[v] = 1;
    
    long long prod1 = 1, prod2 = 1;
    int cnt = 0;
    
    for(int u : adj[v]) {
        if(u == p) continue;
        dfs(u, v);
        
        dp1[v] = (dp1[v] * (dp1[u] + dp2[u])) % MOD;
        
        if(cnt > 0) {
            dp2[v] = (dp2[v] * (dp1[u] + dp2[u])) % MOD;
            prod1 = (prod1 * dp1[u]) % MOD;
            prod2 = (prod2 * dp2[u]) % MOD;
        } else {
            dp2[v] = (dp2[v] * dp1[u]) % MOD;
        }
        
        cnt++;
    }
    
    dp1[v] = (dp1[v] - prod1 + MOD) % MOD;
    dp2[v] = (dp2[v] - prod2 + MOD) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    adj.resize(n);
    dp1.resize(n);
    dp2.resize(n);
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0, -1);
    
    long long ans = (dp1[0] + dp2[0]) % MOD;
    
    cout << ans << "\n";
    
    return 0;
}