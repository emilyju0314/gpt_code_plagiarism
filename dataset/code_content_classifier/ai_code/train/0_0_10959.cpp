#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> d(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> d[i];
    }
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<vector<int>> dp(n, vector<int>(n, INF));
    
    function<void(int, int, int)> dfs = [&](int v, int p, int dist) {
        dp[v][0] = 0;
        dp[v][1] = k;
        for (int u : adj[v]) {
            if (u == p) continue;
            dfs(u, v, dist+1);
            vector<int> ndp(n, INF);
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i + j <= n) {
                        ndp[i+j] = min(ndp[i+j], dp[v][i] + dp[u][j] + j * d[dist]);
                    }
                }
            }
            dp[v] = ndp;
        }
    };
    
    dfs(0, -1, 0);
    
    cout << dp[0][1] << endl;
    
    vector<int> centers(n);
    
    function<void(int, int, int)> assign_centers = [&](int v, int p, int dist) {
        centers[v] = 1;
        for (int u : adj[v]) {
            if (u == p) continue;
            if (dp[v][centers[v]] == dp[v][centers[u]] + dp[u][centers[u]] + centers[u] * d[dist]) {
                centers[u] = centers[v];
                assign_centers(u, v, dist+1);
            } else {
                centers[u] = ++centers[0];
                assign_centers(u, v, dist+1);
            }
        }
    };
    
    assign_centers(0, -1, 0);
    
    for (int i = 0; i < n; i++) {
        cout << centers[i] << " ";
    }
    
    return 0;
}