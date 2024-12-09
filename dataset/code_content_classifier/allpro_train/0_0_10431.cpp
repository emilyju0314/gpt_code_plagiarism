#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> visit_parity;
vector<bool> visited;
vector<int> path;

bool dfs(int v) {
    visited[v] = true;
    path.push_back(v);
    for (int u : adj[v]) {
        if (!visited[u]) {
            if (dfs(u)) {
                return true;
            }
        } else if (find(path.begin(), path.end(), u) != path.end() && visit_parity[u] % 2 == 1) {
            path.push_back(u);
            return true;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    visit_parity.resize(n + 1);
    visited.resize(n + 1, false);
    path.reserve(4 * n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> visit_parity[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout << path.size() << endl;
                for (int j : path) {
                    cout << j << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}