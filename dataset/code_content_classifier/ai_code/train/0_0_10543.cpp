#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int cost;
};

int main() {
    int N, M, L;
    cin >> N >> M >> L;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) {
        // Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[i][i] = 0;
        pq.push({0, i});
        while (!pq.empty()) {
            int d = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (dist[i][v] < d) continue;
            for (const Edge& e : graph[v]) {
                if (dist[i][v] + e.cost < dist[i][e.to] && dist[i][v] + e.cost <= L) {
                    dist[i][e.to] = dist[i][v] + e.cost;
                    pq.push({dist[i][e.to], e.to});
                }
            }
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        int result = (dist[s][t] != INF) ? dist[s][t] / L : -1;
        cout << result << endl;
    }

    return 0;
}