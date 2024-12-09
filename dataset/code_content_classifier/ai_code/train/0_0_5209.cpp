#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int groups = 0;
    for (int i = 1; i <= n; i++) {
        if (adjList[i].size() == 1 && !visited[i]) {
            dfs(i, adjList, visited);
            groups++;
        }
    }

    cout << groups << endl;

    return 0;
}