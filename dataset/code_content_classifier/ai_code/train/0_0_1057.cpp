#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> b, w;
vector<int> dp_be, dp_bw;

void dfs(int v, int p) {
    dp_be[v] = 0;
    dp_bw[v] = w[v] - b[v];
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            dp_be[v] += max(dp_be[u], dp_bw[u]);
            dp_bw[v] += max(dp_be[u] + w[v] - b[v], dp_bw[u]);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        adj.clear();
        adj.resize(n);
        
        b.clear();
        w.clear();
        b.resize(n);
        w.resize(n);
        
        dp_be.clear();
        dp_bw.clear();
        dp_be.resize(n);
        dp_bw.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        dfs(0, -1);
        
        cout << dp_be[0] << endl;
    }

    return 0;
}