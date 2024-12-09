#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

vector<int> graph[MAXN];
int parent[MAXN];
int level[MAXN];

void dfs(int u, int p = -1, int l = 0) {
    parent[u] = p;
    level[u] = l;
    for (int v : graph[u]) {
        if (v != p) {
            dfs(v, u, l + 1);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    dfs(1);
    
    for (int i = 2; i <= n; i++) {
        if (i == 2) {
            cout << 1 << endl;
        } else {
            int node = i;
            int prev = parent[node];
            int lca = prev;
            
            while (level[lca] >= 2) {
                prev = parent[lca];
                lca = prev;
            }
            
            cout << (i == lca ? (lca - 1) * 10 + 1 : node) << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}