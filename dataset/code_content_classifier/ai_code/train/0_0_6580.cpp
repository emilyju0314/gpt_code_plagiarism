#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int x[MAXN];
int y[MAXN];
int z[MAXN];
int dp[MAXN];
int ans[MAXN];

void dfs(int u, int p) {
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u] = max(dp[u], dp[v] + abs(x[u] - x[v]) + abs(y[u] - y[v]) + abs(z[u] - z[v]));
        }
    }
}

void dfs2(int u, int p, int par_val) {
    for (int v : adj[u]) {
        if (v != p) {
            int val = max(par_val, dp[v] + abs(x[u] - x[v]) + abs(y[u] - y[v]) + abs(z[u] - z[v]));
            ans[v] = val;
            dfs2(v, u, val);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0, 0);
    
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}