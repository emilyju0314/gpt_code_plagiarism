#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, vector<vector<int>>& adj, vector<int>& colors, int target_color) {
    if (colors[u] != target_color) {
        int steps = 1;
        target_color = colors[u];
        for (int v : adj[u]) {
            steps += dfs(v, adj, colors, target_color);
        }
        return steps;
    } else {
        int steps = 0;
        for (int v : adj[u]) {
            steps += dfs(v, adj, colors, target_color);
        }
        return steps;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n + 1);
    vector<int> colors(n + 1);
    
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }
    
    int steps = dfs(1, adj, colors, 0);
    
    cout << steps << endl;
    
    return 0;
}