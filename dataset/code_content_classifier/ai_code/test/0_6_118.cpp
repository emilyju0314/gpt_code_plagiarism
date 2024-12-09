#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

vector<vector<int>> adj;
vector<long long> dp;

void dfs(int u, int parent) {
    dp[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            dp[u] = (dp[u] * (dp[v] + 1)) % MOD;
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    dp.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    cout << dp[1] << endl;

    return 0;
}