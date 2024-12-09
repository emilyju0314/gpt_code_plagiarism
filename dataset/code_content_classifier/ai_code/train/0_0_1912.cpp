#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353
#define ll long long

using namespace std;

vector<int> colors;
vector<vector<int>> adj;
ll ans = 1;

int dfs(int u, int p, vector<int>& color_count) {
    int cnt = colors[u] > 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        cnt += dfs(v, u, color_count);
    }
    if (colors[u] == 0 || colors[u] == color_count.size()) {
        color_count.push_back(cnt);
    }
    return cnt;
}

void solve(int u, int p) {
    vector<int> color_count;
    int cnt = dfs(u, p, color_count);

    if (color_count.size() == 1) {
        for (int i = 0; i < cnt; i++) {
            ans = (ans * (ll) k) % MOD;
        }
    } else {
        for (int c : color_count) {
            solve(u, p);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    colors.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1, 0);

    cout << ans << endl;

    return 0;
}