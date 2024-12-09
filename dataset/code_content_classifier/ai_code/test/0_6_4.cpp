#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int n, k;
vector<int> a;
vector<vector<pair<int, int>>> adj;
long long totalHappiness = 0;

pair<int, int> dfs(int u, int p) {
    pair<int, int> res = {0, 0};
    for (auto neighbor : adj[u]) {
        int v = neighbor.first;
        int t = neighbor.second;
        if (v != p) {
            auto sub = dfs(v, u);
            if (t == 1) {
                totalHappiness += (1LL * sub.first * a[u]) % MOD;
                totalHappiness %= MOD;
                totalHappiness += (1LL * sub.second * a[v]) % MOD;
                totalHappiness %= MOD;
                res.first += sub.first + 1LL * a[v];
                res.second += sub.second;
            } else {
                totalHappiness += (1LL * sub.second * a[u]) % MOD;
                totalHappiness %= MOD;
                totalHappiness += (1LL * sub.first * a[v]) % MOD;
                totalHappiness %= MOD;
                res.first += sub.second;
                res.second += sub.first + 1LL * a[v];
            }
        }
    }
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

    dfs(0, -1);

    cout << totalHappiness << endl;

    return 0;
}