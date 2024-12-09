#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> dfs(int v, vector<int>& a, vector<vector<int>>& adj, vector<int>& freq, unordered_map<int, int>& count) {
    vector<int> res = {a[v-1]};
    freq[a[v-1]]++;
    
    for (int u : adj[v]) {
        vector<int> child_res = dfs(u, a, adj, freq, count);
        for (int x : child_res) {
            res.push_back(x);
            freq[x]++;
        }
    }
    
    if (freq[a[v-1]] < 2) {
        count[a[v-1]]--;
    }
    
    return res;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<int>> adj(n+1);
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        
        while (q--) {
            int v, l, k;
            cin >> v >> l >> k;
            
            vector<int> freq(n+1, 0);
            unordered_map<int, int> count;
            
            dfs(v, a, adj, freq, count);
            
            vector<pair<int, int>> sorted_count;
            for (auto it : count) {
                sorted_count.push_back({it.second, it.first});
            }
            sort(sorted_count.begin(), sorted_count.end());
            
            for (int i = 0; i < sorted_count.size(); i++) {
                cout << sorted_count[i].second << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}