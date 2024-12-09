#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> colors;
vector<vector<int>> adj;
vector<int> nice_edges;

void dfs(int v, int parent_color) {
    int curr_color = colors[v];
    for(int u : adj[v]) {
        if(u == parent || colors[u] == 0) continue;
        if(curr_color != 0 && curr_color != colors[u]) {
            nice_edges.push_back({v, u});
            continue;
        }
        dfs(u, parent_color);
    }
}

int main() {
    int n;
    cin >> n;
    
    colors.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> colors[i];
    }
    
    adj.resize(n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    
    cout << nice_edges.size() << endl;
    
    return 0;
}