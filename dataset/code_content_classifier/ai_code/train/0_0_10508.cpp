#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> subtreeSizes;
vector<int> result;

void dfs(int node, int parent) {
    visited[node] = true;
    subtreeSizes[node] = 1;
    
    for (int neighbor : adjList[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            subtreeSizes[node] += subtreeSizes[neighbor];
        }
    }
}

void buildTDecomposition(int node, int parent) {
    vector<int> nodes;
    nodes.push_back(node + 1);
    
    for (int neighbor : adjList[node]) {
        if (neighbor != parent) {
            if (2 * subtreeSizes[neighbor] <= subtreeSizes.size()) {
                nodes.push_back(neighbor + 1);
            } else {
                buildTDecomposition(neighbor, node);
            }
        }
    }
    
    result.push_back(nodes);
}

int main() {
    int n;
    cin >> n;
    
    adjList.resize(n);
    visited.resize(n, false);
    subtreeSizes.resize(n);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    dfs(0, -1);
    buildTDecomposition(0, -1);
    
    cout << result.size() << endl;
    for (auto& nodes : result) {
        cout << nodes.size() << " ";
        for (int node : nodes) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < result.size() - 1; i++) {
        cout << "1 " << result[i][0] << " " << result[i + 1][0] << endl;
    }
    
    return 0;
}