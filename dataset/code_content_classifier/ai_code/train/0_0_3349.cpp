#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj; // Adjacency list representing the tree
vector<bool> visited;
vector<int> parent;
vector<pair<int, int>> paths;
bool possible = true;

void dfs(int node, int p) {
    visited[node] = true;
    parent[node] = p;

    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child, node);
        } else if (child != p && possible) {
            // Construct the decomposition
            possible = false;
            cout << "Yes" << endl;
            cout << "2" << endl;
            cout << child << " " << node << endl;
            cout << parent[child] << " " << child << endl;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    visited.assign(n + 1, false);
    parent.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    if (possible) {
        cout << "No" << endl;
    }

    return 0;
}