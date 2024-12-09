#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dfs(int v, vector<int> &a, vector<vector<int>> &adj, vector<int> &ancestors) {
    ancestors.push_back(a[v-1]);
    int ans = 0;
    
    for(int u : adj[v]) {
        ans += dfs(u, a, adj, ancestors);
    }
    
    return ans + 1;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<int>> adj(n+1);
        for(int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        
        for(int i = 0; i < q; i++) {
            int v, l, k;
            cin >> v >> l >> k;
            
            vector<int> ancestors;
            int count = dfs(v, a, adj, ancestors);
            
            map<int, int> freq;
            for(int num : ancestors) {
                freq[num]++;
            }
            
            vector<pair<int, int>> sortedFreq(freq.begin(), freq.end());
            sort(sortedFreq.begin(), sortedFreq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            });
            
            vector<int> result;
            for(auto& p : sortedFreq) {
                if(p.second >= l) result.push_back(p.first);
            }
            
            if(result.size() < k) cout << -1 << " ";
            else cout << result[k-1] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}