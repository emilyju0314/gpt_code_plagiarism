#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int max_val;
    int min_val;
    int sum_val;
};

vector<vector<pair<int, int>>> adj;
vector<Node> nodes;

void dfs(int u, int parent) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        if (v == parent) continue;
        
        dfs(v, u);
        
        nodes[u].max_val = max(nodes[u].max_val, nodes[v].max_val + edge.second);
        nodes[u].min_val = min(nodes[u].min_val, nodes[v].min_val + edge.second);
        nodes[u].sum_val += nodes[v].sum_val + edge.second;
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n);
    nodes.resize(n);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        u--; v--;
        adj[u].push_back({v, val});
        adj[v].push_back({u, val});
    }
    
    dfs(0, -1);
    
    if (nodes[0].sum_val % 2 != 0 || nodes[0].max_val > nodes[0].sum_val / 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << n - 1 << endl;
        
        for (int i = 1; i < n; i++) {
            int parent = i;
            for (auto& edge : adj[i]) {
                int child = edge.first;
                int val = edge.second;
                int x = (nodes[child].max_val % 2 == 0) ? (val + nodes[child].max_val/2) : (val - nodes[child].max_val/2);
                
                cout << parent + 1 << " " << child + 1 << " " << x << endl;
            }
        }
    }
    
    return 0;
}