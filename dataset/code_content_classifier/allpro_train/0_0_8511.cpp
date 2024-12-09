#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& beauty, vector<int>& l, vector<int>& r) {
    int sum = 0;
    for (int v : adj[u]) {
        if (v != parent) {
            sum += dfs(v, u, adj, beauty, l, r);
        }
    }
    
    int val = min(r[u], sum - beauty[u]);
    beauty[u] = max(l[u], val);
    
    return sum + beauty[u] - val;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> l(n+1), r(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
        }
        
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> beauty(n+1);
        dfs(1, 0, adj, beauty, l, r);
        
        int max_beauty = 0;
        for (int v : beauty) {
            max_beauty += abs(v);
        }
        
        cout << max_beauty << endl;
    }
    
    return 0;
}