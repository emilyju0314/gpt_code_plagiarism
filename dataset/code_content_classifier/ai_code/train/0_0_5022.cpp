#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> depths;
vector<int> max_dep;
int max_depth;
int diam;

void dfs(int v, int p, int d) {
    depths[v] = d;
    max_dep[v] = d;
    for (auto u : graph[v]) {
        if (u.first == p) continue;
        dfs(u.first, v, d + u.second);
        max_dep[v] = max(max_dep[v], max_dep[u.first]);
    }
}

void dfs2(int v, int p, int d) {
    diam = max(diam, d);
    max_dep[v] = max(max_dep[v], d);
    for (auto u : graph[v]) {
        if (u.first == p) continue;
        dfs2(u.first, v, max(d + u.second, max_dep[u.first] + u.second));
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    depths.resize(n);
    max_dep.resize(n);
    
    for (int i = 0; i < n - 1; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        graph[v].push_back({u, w});
        graph[u].push_back({v, w});
    }

    dfs(0, -1, 0);
    max_depth = *max_element(max_dep.begin(), max_dep.end());
    
    dfs2(0, -1, 0);
    
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << max(max_depth, diam + x) << endl;
    }
    
    return 0;
}