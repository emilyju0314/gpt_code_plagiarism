#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj; // Adjacency list for the graph
vector<bool> visited; // Boolean array to mark visited vertices

void dfs(int u, vector<int>& weights, vector<bool>& removed) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, weights, removed);
        }
    }

    if (weights[u] < weights[u] + weights[v]) {
        removed[u] = true; // Remove the edge if the condition is not satisfied
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int A, B, Y;
        cin >> A >> B >> Y;
        A--; B--; // Adjust indices to 0-based

        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    visited.assign(N, false);
    vector<bool> removed(N, false);

    dfs(0, weights, removed); // Start DFS from vertex 0

    int count = 0;
    for (bool edge_removed : removed) {
        if (edge_removed) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}