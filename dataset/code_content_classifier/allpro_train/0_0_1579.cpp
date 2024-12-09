#include <bits/stdc++.h>
using namespace std;

vector<int> query(vector<int>& nodes) {
    cout << "? " << nodes.size() << " ";
    for(int node : nodes) {
        cout << node << " ";
    }
    cout << endl;
    
    int x, d;
    cin >> x >> d;
    return {x, d};
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> nodes;
    for(int i = 1; i <= n; i++) {
        nodes.push_back(i);
    }
    
    vector<int> ans = query(nodes);
    int node1 = ans[0];
    
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        
        nodes.clear();
        for(int i = 1; i <= n; i++) {
            if(abs(i-node1) > mid) {
                nodes.push_back(i);
            }
        }
        
        ans = query(nodes);
        if(ans[1] > mid) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    cout << "! " << node1 << " " << nodes[r-1] << endl;
    string res;
    cin >> res;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        solve();
        
        string res;
        cin >> res;
        if(res == "Incorrect") {
            break;
        }
    }
    
    return 0;
}