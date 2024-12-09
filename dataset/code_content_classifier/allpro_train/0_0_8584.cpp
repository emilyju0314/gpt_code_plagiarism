#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 15005;

int n;
vector<int> adj[MAX_N];
int dp[MAX_N];

int dfs(int u, int p) {
    dp[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dp[u] += dfs(v, u);
        }
    }
    return dp[u];
}

int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i];
    }

    cout << ans << endl;

    return 0;
}