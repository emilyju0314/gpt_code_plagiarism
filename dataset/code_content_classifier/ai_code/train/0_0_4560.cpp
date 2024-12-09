#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

vector<int> values;
vector<vector<int>> adj;
vector<bool> visited;
ll ans;

int dfs(int u, int d) {
    visited[u] = true;
    ll sum = values[u];
    for(int v : adj[u]) {
        if(!visited[v]) {
            ll t = dfs(v, d + 1);
            sum = (sum + t) % MOD;
            ans = (ans + (t * (values[u] % MOD) * ((d % 2 == 0) ? 1 : -1) + MOD) % MOD) % MOD;
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    
    values.resize(n);
    for(int i = 0; i < n; i++)
        cin >> values[i];
    
    adj.resize(n);
    visited.assign(n, false);
    
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    ans = 0;
    dfs(0, 0);
    
    cout << ans % MOD << endl;
    
    return 0;
}