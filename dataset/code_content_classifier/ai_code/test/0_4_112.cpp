#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, char>>> adj;
vector<string> strings;
vector<vector<int>> parent;
vector<vector<int>> depth;

void dfs(int u, int p, int d) {
    parent[u][0] = p;
    depth[u][0] = d;
    
    for (int i = 1; i < 20; i++) {
        if (parent[u][i-1] != -1) {
            parent[u][i] = parent[parent[u][i-1]][i-1];
            depth[u][i] = depth[u][i-1] + depth[parent[u][i-1][i-1]];
        } else {
            break;
        }
    }
    
    for (auto& neighbor : adj[u]) {
        int v = neighbor.first;
        char c = neighbor.second;
        
        if (v != p) {
            strings[v] = strings[u] + c;
            dfs(v, u, d+1);
        }
    }
}

tuple<int, int> lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    int diff = depth[u] - depth[v];
    int ans = 0;
    
    for (int i = 0; diff > 0; i++) {
        if (diff % 2 == 1) {
            ans += depth[u][i];
            u = parent[u][i];
        }
        diff /= 2;
    }
    
    if (u == v) return {u, ans};
    
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            ans += depth[u][i] + depth[v][i];
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    
    ans += depth[u][0] + depth[v][0];
    return {parent[u][0], ans};
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    adj.resize(n);
    strings.resize(n, "");
    parent.assign(n, vector<int>(20, -1));
    depth.assign(n, vector<int>(20, 0));
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    
    dfs(0, -1, 0);
    
    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--; v--;
        
        int total_occurrences = 0;
        
        for (int j = l-1; j < r; j++) {
            string str = strings[u] + strings[v];
            string s = strings[j];
            int cnt = 0;
            for (size_t k = 0; k + str.size() <= s.size(); k++) {
                if (s.substr(k, str.size()) == str) {
                    cnt++;
                }
            }
            total_occurrences += cnt;
        }
        
        cout << total_occurrences << endl;
    }
    
    return 0;
}