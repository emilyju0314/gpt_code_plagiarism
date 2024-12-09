#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> capacity;
vector<vector<int>> flow;
vector<int> parent;

int fordFulkerson(int source, int sink) {
    int maxFlow = 0;
    while (true) {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(source);
        while (!q.empty() && parent[sink] == -1) {
            int u = q.front();
            q.pop();
            for (auto& v : graph[u]) {
                if (parent[v.first] == -1 && capacity[u][v.first] - flow[u][v.first] > 0) {
                    parent[v.first] = u;
                    q.push(v.first);
                }
            }
        }
        if (parent[sink] == -1) {
            break;
        }
        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
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
    cin >> n >> m;
    graph.resize(n + 1);
    capacity.assign(n + 1, vector<int>(n + 1, 0));
    flow.assign(n + 1, vector<int>(n + 1, 0));
    parent.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        capacity[a][b] = c;
        capacity[b][a] = c;
    }

    int maxFlow = fordFulkerson(1, n);

    cout << maxFlow << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }

    return 0;
}