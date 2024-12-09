#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

vector<int> adj[300005];
int dp[300005][2]; // dp[i][0] represents the number of ways to choose an independent set in the subtree rooted at node i such that node i is not included in the set
                   // dp[i][1] represents the number of ways to choose an independent set in the subtree rooted at node i such that node i is included in the set

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] = (1LL * dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
        dp[u][1] = (1LL * dp[u][1] * dp[v][0]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    int ans = (dp[0][0] + dp[0][1]) % MOD;
    cout << ans << endl;

    return 0;
}