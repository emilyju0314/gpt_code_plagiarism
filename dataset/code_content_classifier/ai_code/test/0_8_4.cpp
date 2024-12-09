#include <iostream>
#include <vector>
#include <cstring>
#define mod 1000000007
using namespace std;

int n, k;
vector<int> a;
vector<vector<pair<int, int>>> adj;
long long total = 0;

long long dfs(int v, int p, int c, vector<vector<long long>>& dp) {
    long long res = a[v];
    for (auto u : adj[v]) {
        if (u.first == p) continue;
        res = (res + dfs(u.first, v, u.second, dp)) % mod;
    }
    dp[v][0] = res;
    for (auto u : adj[v]) {
        if (u.first == p) continue;
        if (u.second == c) {
            total = (total + res * dp[u.first][1] % mod) % mod;
            res = (res + dp[u.first][1]) % mod;
        } else {
            total = (total + res * dp[u.first][0] % mod) % mod;
            res = (res + dp[u.first][0]) % mod;
        }
    }
    dp[v][1] = res;
    return res;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    adj.resize(n);
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

    vector<vector<long long>> dp(n, vector<long long>(2, -1));
    dfs(0, -1, -1, dp);

    cout << total << endl;

    return 0;
}