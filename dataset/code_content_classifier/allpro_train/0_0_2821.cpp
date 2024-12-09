#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge {
    int from, to, capacity, flow;
};

vector<vector<int>> adj;
vector<Edge> edges;
vector<int> dist, ptr;

void add_edge(int from, int to, int capacity) {
    adj[from].push_back(edges.size());
    edges.push_back({from, to, capacity, 0});
    adj[to].push_back(edges.size());
    edges.push_back({to, from, 0, 0});
}

bool bfs(int s, int t) {
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int id : adj[u]) {
            int v = edges[id].to;
            if (dist[v] == INF && edges[id].flow < edges[id].capacity) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] != INF;
}

int dfs(int u, int t, int flow) {
    if (u == t || flow == 0) {
        return flow;
    }
    for (int& i = ptr[u]; i < adj[u].size(); i++) {
        int id = adj[u][i];
        int v = edges[id].to;
        if (dist[v] == dist[u] + 1 && edges[id].flow < edges[id].capacity) {
            int pushed = dfs(v, t, min(flow, edges[id].capacity - edges[id].flow));
            if (pushed > 0) {
                edges[id].flow += pushed;
                edges[id^1].flow -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    adj.resize(n+1);
    dist.resize(n+1);
    ptr.resize(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, g;
        cin >> u >> v >> g;
        add_edge(u, v, g == 1 ? 1 : INF);
    }

    int maxFlow = max_flow(s, t);

    int minSaturated = 0;
    for (Edge& edge : edges) {
        if (edge.capacity > 0 && edge.flow == edge.capacity) {
            minSaturated++;
        }
    }

    cout << minSaturated << endl;

    for (int i = 0; i < m; i++) {
        cout << edges[2*i].flow << " " << edges[2*i].capacity << endl;
    }

    return 0;
}