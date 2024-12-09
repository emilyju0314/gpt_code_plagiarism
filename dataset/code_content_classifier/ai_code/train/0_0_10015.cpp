#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 50005;

vector<int> adj[MAX_N];
vector<int> depth(MAX_N);
vector<int> parent(MAX_N);
vector<int> xor_value(MAX_N);

void dfs(int node, int parent_node, int d, int x) {
    parent[node] = parent_node;
    depth[node] = d;
    xor_value[node] = x ^ xor_value[parent_node];
    
    for (int child : adj[node]) {
        if (child != parent_node) {
            dfs(child, node, d+1, xor_value[node]);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> xor_value[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0, 0, 0);
    
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        
        int ans = 0;
        while (u != v) {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }
            ans = max(ans, xor_value[u] ^ xor_value[v]);
            u = parent[u];
        }
        
        cout << max(ans, xor_value[u]) << endl;
    }
    
    return 0;
}