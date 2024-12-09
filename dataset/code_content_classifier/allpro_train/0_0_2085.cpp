#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

vector<int> adj[1000001];
int a, b, m;
long long ans;
long long dp[1000001][2];
int dfs(int node, int parent) {
    if (node == b) {
        dp[node][0] = dp[node][1] = 1;
        return 0;
    }
    dp[node][1] = 1;
    for (auto child : adj[node]) {
        if (child == parent)
            continue;
        int cnt = dfs(child, node);
        dp[node][0] = (dp[node][0] * (dp[child][0] + dp[child][1])) % MOD;
        dp[node][1] = (dp[node][1] * dp[child][1]) % MOD;
        if (cnt == 0 && a != node) {
            dp[node][1] = (dp[node][1] + dp[child][0]) % MOD;
        }
    }
    return node == a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> m >> a >> b;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(a, -1);
    ans = (m * dp[a][1]) % MOD;
    cout << ans << "\n";
    return 0;
}