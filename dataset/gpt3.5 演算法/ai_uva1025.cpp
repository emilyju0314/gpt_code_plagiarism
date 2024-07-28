#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int numVertices, numEdges;
vector<vector<int>> graph;
vector<int> low, disc, parent;
vector<bool> visited;
vector<pair<int, int>> edges;
int dfsNum, numSCC;
stack<int> s;

void tarjanSCC(int u) {
    low[u] = disc[u] = dfsNum++;
    s.push(u);
    visited[u] = true;

    for (int v : graph[u]) {
        if (disc[v] == -1) {
            tarjanSCC(v);
            low[u] = min(low[u], low[v]);
        } else if (visited[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        while (true) {
            int v = s.top();
            s.pop();
            visited[v] = false;
            if (v == u) break;
        }
        numSCC++;
    }
}

int main() {
    int numTestCases, caseNum = 1;
    cin >> numTestCases;

    while (numTestCases--) {
        cin >> numVertices >> numEdges;

        graph.clear();
        graph.resize(numVertices);
        low.assign(numVertices, -1);
        disc.assign(numVertices, -1);
        visited.assign(numVertices, false);
        parent.assign(numVertices, -1);
        edges.clear();
        dfsNum = numSCC = 0;

        for (int i = 0; i < numEdges; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            edges.push_back(make_pair(u, v));
        }

        for (int u = 0; u < numVertices; u++) {
            if (disc[u] == -1) {
                tarjanSCC(u);
            }
        }

        // Check if the graph is strongly connected
        bool isSC = (numSCC == 1);

        cout << "Case " << caseNum++ << ": ";
        if (!isSC) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
