#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> colors;
vector<vector<int>> adj;
vector<bool> visited;

bool checkSubtreeAnnoy(int node) {
    visited[node] = true;
    
    bool differentColors = false;
    for(int child : adj[node]) {
        if(!visited[child]) {
            if(colors[child] != colors[node]) {
                differentColors = true;
            }
            differentColors = differentColors || checkSubtreeAnnoy(child);
        }
    }
    
    return differentColors;
}

int main() {
    int n;
    cin >> n;
    
    colors.resize(n+1);
    adj.resize(n+1);
    visited.resize(n+1, false);
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> colors[i];
    }
    
    int root = 1;
    while(adj[root].size() == 1) {
        root++; // Find a non-leaf node to act as the root
    }
    
    bool annoyed = checkSubtreeAnnoy(root);
    
    if(!annoyed) {
        cout << "YES" << endl;
        cout << root << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}