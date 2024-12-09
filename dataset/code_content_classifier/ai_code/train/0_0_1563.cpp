#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

vector<vector<int>> adj;
vector<int> dp1, dp2;

void dfs(int u, int p) {
    dp1[u] = dp2[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp1[u] = (1LL * dp1[u] * (dp1[v] + dp2[v])) % MOD;
        dp2[u] = (1LL * dp2[u] * dp1[v]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    dp1.resize(n + 1);
    dp2.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int result = (dp1[1] + dp2[1]) % MOD;
    cout << result << endl;

    return 0;
}