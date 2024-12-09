#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isSunny(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (adjList[u].size() == 0) {
            return false;
        }
        for (int v : adjList[u]) {
            if (visited[v]) {
                continue;
            }
            visited[v] = true;
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    if (isSunny(n, adjList)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}