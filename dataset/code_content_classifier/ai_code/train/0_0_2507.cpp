#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> edges;
    set<int> nodes;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v});
        nodes.insert(u);
        nodes.insert(v);
    }

    vector<int> count(n + 1, 0);
    for (auto edge : edges) {
        count[edge.first]++;
        count[edge.second]++;
    }

    int max_neighbors = 0;
    for (int i = 1; i <= n; i++) {
        max_neighbors = max(max_neighbors, count[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (count[i] == max_neighbors) {
            cout << i << " ";
        }
    }

    return 0;
}