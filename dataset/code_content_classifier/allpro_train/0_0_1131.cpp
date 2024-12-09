#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<int> path;

int shortestCycle(int u, int mask) {
    if (mask == ((1 << V) - 1)) {
        if (graph[u][0] != INF) {
            return graph[u][0];
        } else {
            return INF;
        }
    }

    if (path[u] != -1) {
        return path[u];
    }

    int res = INF;

    for (int v = 0; v < V; v++) {
        if ((mask & (1 << v)) == 0 && graph[u][v] != INF) {
            int newMask = mask | (1 << v);
            res = min(res, graph[u][v] + shortestCycle(v, newMask));
        }
    }

    path[u] = res;
    return res;
}

int main() {
    cin >> V >> E;

    graph.assign(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s][t] = d;
    }

    path.assign(V, -1);

    int distance = shortestCycle(0, 1);
    if (distance == INF) {
        cout << -1 << endl;
    } else {
        cout << distance << endl;
    }

    return 0;
}