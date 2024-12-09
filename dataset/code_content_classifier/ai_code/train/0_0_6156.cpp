#include <iostream>
#include <vector>

using namespace std;

vector<int> colors;
vector<vector<int>> adj;
vector<int> visited;
int k = 0;

bool dfs(int u, int c) {
    visited[u] = 1;
    colors[u] = c;
    
    for(int v : adj[u]) {
        if(colors[v] == c) {
            return false; // Cycle found with edges of same color
        }
        if(!visited[v] && !dfs(v, 3 - c)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n);
    visited.resize(n, 0);
    colors.resize(m);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(!dfs(i, 1)) {
                k = 2;
                break;
            }
        }
    }
    
    cout << k << endl;
    for(int c : colors) {
        cout << c << " ";
    }
    cout << endl;
    
    return 0;
}