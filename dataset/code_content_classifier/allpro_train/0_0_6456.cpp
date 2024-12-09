#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    unordered_set<int> governments;
    for (int i = 0; i < k; i++) {
        int gov;
        cin >> gov;
        governments.insert(gov);
    }

    vector<vector<int>> adjList(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int maxEdges = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (governments.count(i) || governments.count(j)) {
                continue;
            }
            bool canAddEdge = true;
            for (int gov : governments) {
                if ((adjList[i].size() + adjList[j].size()) == 2 && adjList[i][0] == adjList[j][0]) {
                    canAddEdge = false;
                    break;
                }
                if (governments.count(adjList[gov][0])) {
                    canAddEdge = false;
                    break;
                }
            }
            if (canAddEdge) {
                maxEdges++;
            }
        }
    }

    cout << maxEdges << endl;

    return 0;
}