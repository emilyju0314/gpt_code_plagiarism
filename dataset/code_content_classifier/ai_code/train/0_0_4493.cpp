#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCycle(int v, vector<vector<int>>& adjList, vector<int>& color) {
    if (color[v] == 2) {
        return false;
    }
    if (color[v] == 1) {
        return true;
    }
    color[v] = 1;
    for (int u : adjList[v]) {
        if (isCycle(u, adjList, color)) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int main() {
    int n, m, u, v, k;
    cin >> n >> m >> u >> v >> k;
    
    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adjList[from-1].push_back(to-1);
    }

    vector<int> color(n, 0);

    if (isCycle(u-1, adjList, color)) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE" << endl;
    }

    return 0;
}