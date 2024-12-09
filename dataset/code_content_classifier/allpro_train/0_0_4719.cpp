#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

void dfs(int u, vector<vector<int>>& adj, vector<int>& ans, vector<int>& subtree_size, vector<int>& ways) {
    for(int v : adj[u]) {
        dfs(v, adj, ans, subtree_size, ways);
        subtree_size[u] += subtree_size[v];
        ways[u] = (ways[u] * ways[v]) % MOD;
    }
    ans[u] = (ways[u] + subtree_size[u]) % MOD;
    ways[u]++;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[p-1].push_back(i);
    }
    
    vector<int> ans(n);
    vector<int> subtree_size(n, 1);
    vector<int> ways(n, 1);
    
    dfs(0, adj, ans, subtree_size, ways);
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}