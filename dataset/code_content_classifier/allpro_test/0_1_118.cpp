#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXN = 250005;

vector<int> adj[MAXN];
long long dp[MAXN][3]; // dp[i][j] stores the number of ways to color subtree rooted at i with j different colors

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = dp[u][2] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][2]) % MOD) % MOD;
        dp[u][1] = (dp[u][1] * (dp[v][0] + dp[v][1] + dp[v][2]) % MOD) % MOD;
        dp[u][2] = (dp[u][2] * dp[v][1] % MOD) % MOD;
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

    long long ans = (dp[1][0] + dp[1][1]) % MOD;
    cout << ans << endl;

    return 0;
}