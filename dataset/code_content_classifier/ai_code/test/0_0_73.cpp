#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> vis;
vector<int> depth;

int timer = 0;

void dfs(int v, int p) {
    vis[v] = 1;
    depth[v] = timer++;
    for(int u : adj[v]) {
        if(u == p) continue;
        if(!vis[u])
            dfs(u, v);
        else if(depth[u] < depth[v])
            cout << 1 << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    vis.resize(n);
    depth.resize(n);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = n*(n-1)/2;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, -1);
    }

    cout << ans << endl;

    return 0;
}