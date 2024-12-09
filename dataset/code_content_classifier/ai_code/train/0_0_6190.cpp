#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> a;
vector<vector<int>> adj;
vector<int> subtree_min;

void dfs(int node, int parent) {
    vector<int> subtree_values;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            subtree_values.push_back(subtree_min[child]);
        }
    }
    
    sort(subtree_values.begin(), subtree_values.end());
    int to_take = min(k - 1, (int)subtree_values.size());
    
    subtree_min[node] = a[node];
    for (int i = 0; i < to_take; i++) {
        subtree_min[node] = min(subtree_min[node], subtree_values[i]);
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    adj.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    subtree_min.resize(n);
    dfs(0, -1);
    
    cout << subtree_min[0] << endl;
    
    return 0;
}