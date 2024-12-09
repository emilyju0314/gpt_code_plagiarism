#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<pair<int, int>> newEdges;
    vector<bool> used(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;
        if (!used[u] && !used[v]) {
            newEdges.push_back({u, v});
            used[u] = used[v] = true;
        }
    }

    if (newEdges.size() != m) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < m; i++) {
            cout << newEdges[i].first << " " << newEdges[i].second << endl;
        }
    }

    return 0;
}