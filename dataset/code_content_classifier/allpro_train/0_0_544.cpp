#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, k;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
bool found = false;
vector<int> cycle;

void dfs(int v, int depth) {
    visited[v] = true;
    
    for(int u : adj[v]) {
        if(!visited[u]) {
            parent[u] = v;
            dfs(u, depth + 1);
        } else if(depth >= k + 1 && !found) {
            found = true;
            int cur = v;
            cycle.push_back(cur);
            
            while(parent[cur] != u) {
                cur = parent[cur];
                cycle.push_back(cur);
            }
            
            cycle.push_back(u);
            cycle.push_back(v);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    
    adj.resize(n + 1);
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, 1);
        }
    }
    
    cout << cycle.size() << endl;
    for(int v : cycle) {
        cout << v << " ";
    }
    
    return 0;
}