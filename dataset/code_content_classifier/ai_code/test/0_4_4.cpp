#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
vector<vector<pair<int, bool>>> adj;
vector<int> a;
int k;

int dfs(int u, int p, int cnt, int& res) {
    int res_u = 0;
    for (auto [v, c] : adj[u]) {
        if (v == p) continue;
        int res_v = dfs(v, u, cnt, res);
        if (!c && cnt > 0) {
            res += max(0, res_v);
            cnt--;
        }
        res_u = (res_u + max(0, res_v)) % mod;
    }
    res = (res + (a[u] * (1LL + res_u) % mod) % mod) % mod;
    return res_u;
}

int main() {
    int n;
    cin >> n >> k;
    a.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    int res = 0;
    dfs(0, -1, k, res);
    cout << res << endl;

    return 0;
}