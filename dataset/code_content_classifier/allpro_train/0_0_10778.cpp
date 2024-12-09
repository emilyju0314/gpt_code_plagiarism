#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007

using namespace std;

int d, n;
vector<int> a;
vector<vector<int>> adj;
vector<vector<long long>> dp;

long long dfs(int u, int p) {
    if(dp[u][d] != -1) {
        return dp[u][d];
    }

    dp[u][0] = 1;
    for(int v : adj[u]) {
        if(v != p) {
            dp[u][0] = (1 + dp[u][0] + dfs(v, u)) % MOD;
        }
    }

    for(int i = 1; i <= d; i++) {
        dp[u][i] = 1;
        for(int v : adj[u]) {
            if(v != p) {
                dp[u][i] = (dp[u][i] * (dfs(v, u) + 1)) % MOD;
            }
        }
    }

    return dp[u][d];
}

int main() {
    cin >> d >> n;
    a.resize(n+1);
    adj.resize(n+1);
    dp.assign(n+1, vector<long long>(d+1, -1));

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + dfs(i, 0)) % MOD;
    }

    cout << ans << endl;

    return 0;
}