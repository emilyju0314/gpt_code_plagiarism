#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const long long MOD = 1000000007;

vector<int> a;
vector<vector<pair<int, int>>> adj;
int n, k;
long long ans = 0;

pair<int, int> dfs(int u, int p) {
    pair<int, int> res = {0, 0};

    for (auto edge : adj[u]) {
        int v = edge.first;
        int t = edge.second;
        
        if (v == p) continue;

        auto child = dfs(v, u);

        if (t == 0) {
            ans = (ans + 1LL * a[u] * child.first) % MOD;
            res.second += child.second;
        } else {
            ans = (ans + 1LL * a[u] * child.second) % MOD;
            res.first += child.first;
        }

        ans = (ans + 1LL * a[u] * a[v]) % MOD;
        res.first = (res.first + a[v]) % MOD;
        res.second = (res.second + a[v]) % MOD;
    }

    return res;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    dfs(0, -1);

    cout << ans << endl;

    return 0;
}