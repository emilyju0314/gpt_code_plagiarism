#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
vector<pair<int, int>> paths;

void dfs(int v, int p, double x) {
    visited[v] = true;
    parent[v] = p;

    for (int u : adj[v]) {
        if (!visited[u]) {
            paths.push_back({v, u});
            paths.push_back({u, v});
            paths.push_back({u, v});
            dfs(u, v, 1 - x);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n+1);
    visited.assign(n+1, false);
    parent.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0.5);

    cout << paths.size() / 3 << endl;

    for (int i = 0; i < paths.size(); i += 3) {
        cout << 3 << endl;
        cout << paths[i].first << " " << paths[i].second << " " 
             << paths[i+1].first << " " << paths[i+1].second << " 0.5" << endl; 
        cout << paths[i+1].first << " " << paths[i+1].second << " " 
             << paths[i+2].first << " " << paths[i+2].second << " 0.5" << endl; 
    }

    return 0;
}