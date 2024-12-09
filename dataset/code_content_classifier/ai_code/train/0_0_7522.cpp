#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<vector<Edge>> graph;
vector<int> dist;
vector<bool> visited;

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (visited[v]) continue;
        visited[v] = true;

        for (Edge e : graph[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    dist.assign(n, INF);
    visited.assign(n, false);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(Edge(b, c));
        graph[b].push_back(Edge(a, c));
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int fs, fg;
        cin >> fs >> fg;

        dijkstra(0);

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (dist[j] >= fs && dist[j] + fg >= dist[n-1]) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}