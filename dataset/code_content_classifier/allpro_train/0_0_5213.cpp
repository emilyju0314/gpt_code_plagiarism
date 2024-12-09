#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, capacity, flow, id;
};

vector<vector<Edge>> graph;
vector<int> dist, ptr, specialCapacities;

bool bfs(int source, int sink) {
    fill(dist.begin(), dist.end(), -1);
    dist[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const Edge& e : graph[u]) {
            if (dist[e.to] == -1 && e.flow < e.capacity) {
                dist[e.to] = dist[u] + 1;
                q.push(e.to);
            }
        }
    }
    return dist[sink] != -1;
}

int dfs(int u, int flow, int sink) {
    if (u == sink || flow == 0)
        return flow;
    for (int& p = ptr[u]; p < graph[u].size(); p++) {
        Edge& e = graph[u][p];
        if (dist[u] + 1 != dist[e.to] || e.flow == e.capacity)
            continue;
        int pushed = dfs(e.to, min(flow, e.capacity - e.flow), sink);
        if (pushed > 0) {
            e.flow += pushed;
            graph[e.to][e.id].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int DinicMaxFlow(int source, int sink) {
    int maxFlow = 0;
    while (true) {
        if (!bfs(source, sink))
            break;
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(source, INF, sink)) {
            maxFlow += pushed;
        }
    }
    return maxFlow;
}

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    graph.resize(n);
    dist.resize(n);
    ptr.resize(n);
    specialCapacities.resize(k);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].push_back({v-1, w, 0, i});
    }

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < k; j++) {
            cin >> specialCapacities[j];
        }

        for (int j = 0; j < k; j++) {
            graph[0][j].capacity = specialCapacities[j];
            graph[0][j].flow = 0;
            graph[1][j].capacity = specialCapacities[j];
            graph[1][j].flow = 0;
        }

        cout << DinicMaxFlow(0, n-1) << endl;
    }

    return 0;
}