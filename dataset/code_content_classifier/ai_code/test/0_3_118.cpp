#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

vector<int> adj[250001];
int dp[250001][2];

void dfs(int u, int p) {
    dp[u][0] = 1;
    dp[u][1] = 1;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            dp[u][0] = (1LL * dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
            dp[u][1] = (1LL * dp[u][1] * dp[v][0]) % MOD;
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1, 0);
    
    int ans = (dp[1][0] + dp[1][1]) % MOD;
    cout << ans << endl;
    
    return 0;
}