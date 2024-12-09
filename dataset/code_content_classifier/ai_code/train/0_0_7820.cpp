#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> adjList;
vector<unordered_set<int>> importantRoads;
vector<bool> visited;

void dfs(int u, int merchant, int dest) {
    visited[u] = true;
    if (u == dest) return;

    for (int v : adjList[u]) {
        if (!visited[v]) {
            importantRoads[merchant].insert(v);
            dfs(v, merchant, dest);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1);
    importantRoads.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int k;
    cin >> k;

    for (int i = 1; i <= k; i++) {
        int si, li;
        cin >> si >> li;

        dfs(si, i, li);

        cout << importantRoads[i].size() << endl;

        // Reset visited array for the next merchant
        fill(visited.begin(), visited.end(), false);
    }

    return 0;
}