#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_V = 100;
const int INF = 1e9;

int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int parent[MAX_V];
int V;

int fordFulkerson(int source, int sink) {
    int maxFlow = 0;
    while (true) {
        memset(parent, -1, sizeof(parent));
        queue<int> q;
        parent[source] = -2;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < V; v++) {
                if (parent[v] == -1 && cap[u][v] - flow[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        if (parent[sink] == -1) {
            break;
        }

        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, cap[u][v] - flow[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int E;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cap[u][v] = c;
    }

    cout << fordFulkerson(0, V - 1) << endl;

    return 0;
}