#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1); // to store the adjacency list

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> degrees(n+1, 0);
    for (int i = 1; i <= n; i++) {
        degrees[i] = adj[i].size();
    }

    // Find the vertex with maximum degree
    int max_degree = 0;
    int vertex = 1;
    for (int i = 1; i <= n; i++) {
        if (degrees[i] > max_degree) {
            max_degree = degrees[i];
            vertex = i;
        }
    }

    for (int neighbor : adj[vertex]) {
        cout << vertex << " " << neighbor << "\n";
    }

    for (int i = 1; i <= n; i++) {
        if (i != vertex) {
            for (int neighbor : adj[i]) {
                if (neighbor != vertex) {
                    cout << i << " " << neighbor << "\n";
                }
            }
        }
    }

    return 0;
}