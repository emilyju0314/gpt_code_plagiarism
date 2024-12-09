#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> query_a, query_b, query_g;
vector<int> f_values;

bool dfs(int u, int parent, int min_beauty) {
    if (u == 1 && parent != -1) {
        return true;
    }
    
    for (int v : graph[u]) {
        if (v == parent) continue;
        int new_beauty = min(min_beauty, f_values[{u, v}]);
        if (dfs(v, u, new_beauty)) {
            f_values[{u, v}] = new_beauty;
            return true;
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    graph.resize(n+1);
    f_values.resize(n+1);
    
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    int m;
    cin >> m;
    query_a.resize(m);
    query_b.resize(m);
    query_g.resize(m);
    
    for (int i = 0; i < m; i++) {
        cin >> query_a[i] >> query_b[i] >> query_g[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j : graph[i]) {
            f_values[{i, j}] = f_values[{j, i}] = 1000000;
        }
    }
    
    for (int i = 0; i < m; i++) {
        dfs(query_a[i], -1, query_g[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j : graph[i]) {
            if (f_values[{i, j}] == 1000000) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j : graph[i]) {
            cout << f_values[{i, j}] << " ";
        }
    }
    
    return 0;
}