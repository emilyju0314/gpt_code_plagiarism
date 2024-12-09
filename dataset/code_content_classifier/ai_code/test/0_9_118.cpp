#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

vector<int> adj[250005];
long long dp[250005][2];
long long ans = 0;

void dfs(int v, int par) {
    dp[v][0] = dp[v][1] = 1;

    for(int u : adj[v]) {
        if(u == par) continue;
        dfs(u, v);

        dp[v][0] = (dp[v][0] * (dp[u][0] + dp[u][1])) % MOD;
        dp[v][1] = (dp[v][1] * dp[u][0]) % MOD;
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

    ans = (dp[1][0] + dp[1][1]) % MOD;

    cout << ans << endl;

    return 0;
}