#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
int n, m;
vector<int> adj[MAXN];
vector<int> beauty(MAXN);
int ans = 0;

pair<int, int> dfs(int u, int p) {
    pair<int, int> res = {0, 0};
    
    for (int v : adj[u]) {
        if (v == p) continue;
        
        auto [added, total] = dfs(v, u);
        ans = max(ans, added);
        res.first += total;
        res.second = max(res.second, total);
    }
    
    res.first += beauty[u];
    
    return {res.second, res.first};
}

int main() {
    cin >> n >> m;
    
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        beauty[u] = c;
        beauty[v] = c;
    }
    
    dfs(1, 0);
    
    cout << ans << endl;
    
    return 0;
}