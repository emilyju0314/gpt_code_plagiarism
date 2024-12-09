#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        edges.push_back({a, b});
    }

    vector<bool> visited(n + 1, false);
    vector<pair<int, int>> solution;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            for (int j : adjList[i]) {
                if (!visited[j]) {
                    visited[i] = true;
                    visited[j] = true;
                    solution.push_back({i, j});
                    break;
                }
            }
        }
    }

    if (solution.size() < (m / 2)) {
        cout << "No solution" << endl;
    } else {
        for (pair<int, int> path : solution) {
            cout << path.first << " " << path.second << " ";
            for (int i : adjList[path.second]) {
                if (i != path.first) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}