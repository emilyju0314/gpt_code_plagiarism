#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define MOD 1000000007

using namespace std;

typedef long long ll;

vector<vector<pair<int, ll>>> graph;
vector<ll> xor_values;

void dfs(int u, int p, ll xor_val) {
    xor_val ^= xor_values[u];
    for (auto neighbor : graph[u]) {
        int v = neighbor.first;
        ll edge_val = neighbor.second;
        if (v != p) {
            dfs(v, u, xor_val ^ edge_val);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    xor_values.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        u--; v--;
        xor_values[u] ^= t;
        xor_values[v] ^= t;
        graph[u].push_back({v, t});
        graph[v].push_back({u, t});
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        dfs(i, -1, 0);
        ans = (ans + xor_values[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}