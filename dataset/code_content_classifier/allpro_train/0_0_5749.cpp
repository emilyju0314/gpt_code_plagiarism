#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int node, unordered_map<int, vector<int>>& adjList, vector<bool>& visited) {
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

    unordered_map<int, vector<int>> adjList;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    vector<bool> visited(n+1, false);
    dfs(1, adjList, visited);

    int t = 1;
    while (t <= n) {
        bool divisible = true;
        for (int i = 1; i <= n; i++) {
            if (visited[i] && i % t != 0) {
                divisible = false;
                break;
            }
        }
        if (divisible) {
            break;
        }
        t++;
    }

    vector<int> cameras;
    for (int i = 1; i <= n; i++) {
        if (visited[i] && i % t == 0) {
            cameras.push_back(i);
        }
    }

    cout << t << endl;
    cout << cameras.size() << endl;
    for (int camera : cameras) {
        cout << camera << " ";
    }
    cout << endl;

    return 0;
}