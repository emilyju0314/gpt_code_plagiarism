#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

vector<int> adj[250001];
long long dp[250001][2];

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;

    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);

        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    cout << (dp[1][0] + dp[1][1]) % MOD << endl;

    return 0;
}