#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> adj(n);
    vector<int> degrees(n, 0);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degrees[u]++;
        degrees[v]++;
    }
    
    queue<int> leaves;
    for (int i = 0; i < n; i++) {
        if (degrees[i] == 1) {
            leaves.push(i);
        }
    }
    
    bool valid = true;
    while (!leaves.empty()) {
        int curr = leaves.front();
        leaves.pop();
        
        if (curr == adj.size()) {
            valid = false;
            break;
        }
        
        degrees[curr] = 0;
        
        for (int& neighbor : adj[curr]) {
            degrees[neighbor]--;
            if (degrees[neighbor] == 1) {
                leaves.push(neighbor);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (degrees[i] < 3) {
            valid = false;
            break;
        }
    }
    
    if (valid && leaves.size() == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}