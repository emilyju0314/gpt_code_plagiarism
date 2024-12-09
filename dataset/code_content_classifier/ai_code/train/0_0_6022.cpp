#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    vector<pair<int, int>> edges(m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int min_ri = n;
    vector<bool> visited(n+1, false);
    vector<int> ri(n+1, 1);
    
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            visited[j] = false;
        }
        
        for (int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            visited[v] = true;
        }
        
        for (int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            for (int k = 0; k < adj[v].size(); k++) {
                int u = adj[v][k];
                if (!visited[u]) {
                    count++;
                    break;
                }
            }
        }
        
        min_ri = min(min_ri, count);
        ri[i] = count;
    }
    
    cout << min_ri << endl;
    
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        if (ri[u] < ri[v]) {
            cout << u << " " << v << endl;
        } else {
            cout << v << " " << u << endl;
        }
    }
    
    return 0;
}