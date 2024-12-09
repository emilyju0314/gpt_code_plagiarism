#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adjList(n+1);
        set<int> chosenVertices;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        chosenVertices.insert(1);
        for (int i = 2; i <= n; i++) {
            if (adjList[i].size() > adjList[1].size() / 2) {
                chosenVertices.insert(i);
            }
        }

        cout << chosenVertices.size() << endl;
        for (auto vertex : chosenVertices) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}