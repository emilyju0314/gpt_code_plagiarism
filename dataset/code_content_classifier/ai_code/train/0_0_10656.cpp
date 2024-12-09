#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int w;
    vector<pair<int, int>> adj; // {city, length}
};

long long maxGasoline = 0;

long long dfs(vector<Node>& tree, int node, int parent) {
    long long maxChildGasoline = 0;
    for (auto neighbor : tree[node].adj) {
        if (neighbor.first != parent) {
            long long childGasoline = dfs(tree, neighbor.first, node) - neighbor.second;
            maxChildGasoline = max(maxChildGasoline, childGasoline);
        }
    }
    long long totalGasoline = tree[node].w + maxChildGasoline;
    maxGasoline = max(maxGasoline, totalGasoline);
    return totalGasoline;
}

int main() {
    int n;
    cin >> n;
    
    vector<Node> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].w;
    }
    
    for (int i = 0; i < n-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        tree[u].adj.push_back({v, c});
        tree[v].adj.push_back({u, c});
    }
    
    dfs(tree, 0, -1);
    
    cout << maxGasoline << endl;
    
    return 0;
}