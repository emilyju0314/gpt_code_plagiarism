#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
    visited[node] = 1;
    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next, visited, adj);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> elements(m);
    for (int i = 0; i < m; i++) {
        cin >> elements[i];
    }

    vector<vector<int>> adj(m);
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if ((elements[i] & elements[j]) == 0) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> visited(m, 0);
    int components = 0;
    for (int i = 0; i < m; i++) {
        if (visited[i] == 0) {
            dfs(i, visited, adj);
            components++;
        }
    }

    cout << components << endl;

    return 0;
}