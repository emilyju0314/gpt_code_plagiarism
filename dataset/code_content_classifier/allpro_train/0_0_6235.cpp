#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

vector<int> adj[500001];
int n;

pair<int, int> dfs(int u, int p) {
    pair<int, int> res = {0, 1};
    for (int v : adj[u]) {
        if (v == p) continue;
        pair<int, int> tmp = dfs(v, u);
        res.first += tmp.first;
        res.second = (1LL * res.second * tmp.second) % MOD;
        res.first = (res.first + tmp.second) % MOD;
    }
    return res;
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, int> res = dfs(1, 0);

    int ans = (1LL * res.second * (1 << (n - 1))) % MOD;
    cout << ans << endl;

    return 0;
}