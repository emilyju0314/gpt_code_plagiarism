#include <iostream>
#include <vector>

const int MOD = 998244353;

using namespace std;

vector<vector<int>> adj;
vector<int> subtreeSize;
int n;

int dfs(int node, int parent) {
    subtreeSize[node] = 1;
    for (int child : adj[node]) {
        if (child != parent) {
            subtreeSize[node] += dfs(child, node);
        }
    }
    return subtreeSize[node];
}

int main() {
    cin >> n;
    
    adj.resize(n + 1);
    subtreeSize.resize(n + 1);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    
    for (int i = 2; i <= n; i++) {
        ans = (ans * subtreeSize[i]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}