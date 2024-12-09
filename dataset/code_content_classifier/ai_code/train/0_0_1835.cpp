#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int farthest_node;
int max_distance = 0;

void dfs(int node, int distance) {
    visited[node] = true;
    if (distance > max_distance) {
        max_distance = distance;
        farthest_node = node;
    }
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child, distance + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Find the farthest node from any node using DFS
    dfs(1, 0);
    fill(visited.begin(), visited.end(), false);
    max_distance = 0;

    // Find the farthest node from the farthest node using DFS
    dfs(farthest_node, 0);

    cout << max_distance << endl;

    return 0;
}