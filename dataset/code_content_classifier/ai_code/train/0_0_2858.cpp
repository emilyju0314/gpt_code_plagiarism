#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure to store information about each city
struct Node {
    long long maxGas;
    long long maxGasOnPath; // Maximum amount of gas Nut can have at the end of the path
};

vector<vector<pair<int, int>>> adjList; // Adjacency list to store the tree structure
vector<Node> nodes; // Array of nodes to store information about each city

void dfs(int u, int parent) {
    Node currNode;
    currNode.maxGas = nodes[u].maxGas;
    long long maxChildPath = 0;
    
    for (auto edge : adjList[u]) {
        int v = edge.first;
        if (v == parent) {
            continue;
        }
        dfs(v, u);
        
        // If Nut can reach city v with more gas than the previous maximum, update maxChildPath
        maxChildPath = max(maxChildPath, nodes[v].maxGasOnPath + nodes[v].maxGas - edge.second);
    }
    currNode.maxGasOnPath = max(currNode.maxGas, currNode.maxGas + maxChildPath);
    nodes[u] = currNode;
}

int main() {
    int n;
    cin >> n;
    
    nodes.resize(n);
    adjList.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].maxGas;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        adjList[u].push_back({v, c});
        adjList[v].push_back({u, c});
    }
    
    dfs(0, -1);
    cout << nodes[0].maxGasOnPath << endl;
    
    return 0;
}