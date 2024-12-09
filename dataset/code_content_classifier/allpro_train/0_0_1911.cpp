#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

vector<vector<int>> adj;
vector<int> dp;
int k;

void dfs(int u, int p) {
    dp[u] = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u] += dp[v];
        dp[u] %= MOD;
    }
}

int power(int x, int y) {
    int res = 1;
    for(int i = 0; i < y; i++) {
        res *= x;
        res %= MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n >> k;

    adj.resize(n+1);
    dp.resize(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    int ans = 0;
    for(int u = 1; u <= n; u++) {
        ans += power(dp[u], k);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}