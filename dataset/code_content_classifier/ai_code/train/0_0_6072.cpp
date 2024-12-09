#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 205;
vector<int> adj[MAXN];
int dp[MAXN][MAXN][MAXN];
int a[MAXN];

void dfs(int u, int p, int k) {
    dp[u][0][0] = a[u];
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u, k);
        for(int i = 0; i <= k; i++) {
            dp[u][i+1][0] = max(dp[u][i+1][0], dp[v][i][0]);
            for(int j = 1; j <= i; j++) {
                dp[u][i][j] = max(dp[u][i][j], dp[v][i-j][0] + dp[u][i-j][j-1]);
                dp[u][i][j] = max(dp[u][i][j], dp[u][i-j][0] + dp[v][i-j][j-1]);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, 0, sizeof(dp));
    dfs(1, 0, k);

    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = max(ans, dp[1][i][0]);
    }

    cout << ans << endl;

    return 0;
}