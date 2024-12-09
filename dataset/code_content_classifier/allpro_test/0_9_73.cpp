#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2.5e5 + 5;
int parent[MAXN], rnk[MAXN];
int n, m;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (rnk[u] < rnk[v]) swap(u, v);
        parent[v] = u;
        rnk[u] += rnk[v];
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rnk[i] = 1;
    }

    set<int> desert;
    long long ans = 0;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        if (find(u) == find(v)) {
            desert.insert(find(u));
        } else {
            unite(u, v);
        }

        ans += i + 1 - desert.size();
    }
    
    cout << ans << "\n";

    return 0;
}