#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<long long> a;
int n, k;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

long long dfs(int u, int p, long long sum, int tickets) {
    long long ans = 0;
    for (auto neigh : adj[u]) {
        int v = neigh.first;
        int t = neigh.second;
        if (v != p) {
            int new_tickets = tickets + t;
            if (new_tickets > k) continue;
            ans = (ans + dfs(v, u, sum + a[v], new_tickets)) % MOD;
        }
    }
    return (ans + sum) % MOD;
}

int main() {
    cin >> n >> k;
    adj.resize(n);
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    long long ans = 0;
    for (int u = 0; u < n; u++) {
        ans = (ans + dfs(u, -1, 0, 0)) % MOD;
    }
    cout << ans << endl;

    return 0;
}