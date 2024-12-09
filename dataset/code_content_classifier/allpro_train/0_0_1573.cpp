#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> parent(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> parent[i];
    }
    
    vector<vector<int>> tree(n);
    for(int i=1; i<n; i++) {
        tree[parent[i-1]].push_back(i);
    }
    
    vector<int> ans;
    function<void(int)> dfs = [&](int node) {
        ans.push_back(node);
        for(int child : tree[node]) {
            dfs(child);
        }
    };
    
    dfs(0);
    
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    vector<int> operations;
    for(int i=n-1; i>=1; i--) {
        int cur = i;
        while(parent[cur-1] != 0) {
            operations.push_back(cur);
            parent[cur-1] = parent[parent[cur-1]-1];
            cur = parent[cur-1];
        }
    }
    
    cout << operations.size() << endl;
    
    for(int op : operations) {
        cout << op << " ";
    }
    
    return 0;
}