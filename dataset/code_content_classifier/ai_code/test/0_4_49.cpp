#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> freq;

void dfs(int v, const vector<int>& parent, const vector<int>& a, vector<int>& path) {
    path.push_back(a[v]);
    if (freq.count(a[v])) {
        freq[a[v]].push_back(v);
    } else {
        freq[a[v]] = {v};
    }
    if (v == 0) {
        reverse(path.begin(), path.end());
        return;
    }
    dfs(parent[v-1], parent, a, path);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> parent(n-1), a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n-1; i++) {
            cin >> parent[i];
        }
        
        while (q--) {
            int v, l, k;
            cin >> v >> l >> k;
            v--; // 0-based indexing
            
            vector<int> path;
            dfs(v, parent, a, path);
            
            vector<int> unique_path;
            for (int num : path) {
                if (count(path.begin(), path.end(), num) >= l && find(unique_path.begin(), unique_path.end(), num) == unique_path.end()) {
                    unique_path.push_back(num);
                }
            }
            
            sort(unique_path.begin(), unique_path.end(), [&](int x, int y){
                return freq[x].size() < freq[y].size();
            });
            
            if (k-1 < unique_path.size()) {
                cout << unique_path[k-1] << " ";
            } else {
                cout << "-1 ";
            }
            
            // Clear the frequency map for next query
            for (int num : path) {
                freq[num].clear();
            }
        }
        cout << endl;
    }
    
    return 0;
}