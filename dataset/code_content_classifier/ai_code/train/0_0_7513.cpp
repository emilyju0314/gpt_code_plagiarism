#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> subtreeSize;

int dfs(int node) {
    visited[node] = true;
    subtreeSize[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            subtreeSize[node] += dfs(neighbor);
        }
    }
    return subtreeSize[node];
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    subtreeSize.resize(n + 1, 0);
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1);

    if (subtreeSize[1] % 2 == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
    
    return 0;
}