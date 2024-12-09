#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> depth;
vector<int> ans;

void dfs(int v, int d) {
    visited[v] = true;
    depth[v] = d;
    
    ans.push_back({v, d});
    
    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u, d+1);
            ans.push_back({v, d});
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n+1);
    visited.resize(n+1, false);
    depth.resize(n+1);
    
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    cout << ans.size() << endl;
    for(auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}