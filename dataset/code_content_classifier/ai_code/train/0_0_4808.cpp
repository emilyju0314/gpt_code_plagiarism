#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> visited;

bool dfs(int u, int b) {
    visited[u] = 1;
    
    if (u == b) {
        return true;
    }
    
    for (auto edge : graph[u]) {
        int v = edge.first;
        if (!visited[v] && dfs(v, b)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    graph.resize(n+1);
    visited.resize(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
    
    int a, b;
    cin >> a >> b;
    
    if (dfs(a, b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}