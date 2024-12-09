#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<int>& values, vector<int>& parent, vector<unordered_map<int, int>>& occurrences) {
    if (u == 0) {
        occurrences[u][values[u]]++;
        return;
    }
    
    occurrences[u][values[u]]++;
    
    for (int v : adj[u]) {
        if (v != parent[u]) {
            for (auto& p : occurrences[u]) {
                occurrences[v][p.first] = p.second;
            }
            parent[v] = u;
            dfs(v, adj, values, parent, occurrences);
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> values(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            p--;
            adj[p].push_back(i);
        }
        
        vector<int> parent(n, -1);
        vector<unordered_map<int, int>> occurrences(n);
        
        dfs(0, adj, values, parent, occurrences);
        
        while (q--) {
            int v, l, k;
            cin >> v >> l >> k;
            v--;
            vector<pair<int, int>> counts;
            for (auto& p : occurrences[v]) {
                if (p.second >= l) {
                    counts.push_back({p.second, p.first});
                }
            }
            
            sort(counts.begin(), counts.end());
            reverse(counts.begin(), counts.end());
            
            vector<int> result;
            for (auto& pair : counts) {
                result.push_back(pair.second);
            }
            
            if (result.size() >= k) {
                cout << result[k-1] << " ";
            } else {
                cout << "-1 ";
            }
        }
        
        cout << endl;
    }
    
    return 0;
}