#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> articulationPoints;
vector<vector<int>> adjList;
vector<int> parent, visited, disc, low;
int time;

void dfsAP(int u) {
    visited[u] = 1;
    disc[u] = low[u] = time++;
    int children = 0;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfsAP(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1) {
                articulationPoints.push_back(u);
            }
            if (parent[u] != -1 && low[v] >= disc[u]) {
                articulationPoints.push_back(u);
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    adjList.resize(V);
    parent.assign(V, -1);
    visited.assign(V, 0);
    disc.assign(V, 0);
    low.assign(V, 0);
    time = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsAP(i);
        }
    }

    sort(articulationPoints.begin(), articulationPoints.end());

    for (int ap : articulationPoints) {
        cout << ap << endl;
    }

    return 0;
}