#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 0;
    set<int> reachable;
    
    for(int i = 1; i <= n; i++) {
        set<int> new_reachable;
        
        for(int v : adj[i]) {
            if(reachable.count(v) || v == i) new_reachable.insert(v);
        }
        
        if(new_reachable.size() < reachable.size()) {
            ans++;
        } else {
            reachable = new_reachable;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}