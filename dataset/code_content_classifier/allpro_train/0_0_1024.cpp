#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to, cost;
};

void dijkstra(int start, vector<vector<Edge>>& graph, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, current] = pq.top();
        pq.pop();

        if (dist[current] < d) continue;

        for (auto& edge : graph[current]) {
            int next = edge.to;
            long long nextDist = d + edge.cost;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    int N, Q, K;
    cin >> N;

    vector<vector<Edge>> graph(N+1);
    vector<long long> dist(N+1, LLONG_MAX);

    for (int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> Q >> K;

    dijkstra(K, graph, dist);

    for (int j = 0; j < Q; j++) {
        int x, y;
        cin >> x >> y;

        long long ans = dist[x] + dist[y];
        cout << ans << endl;
    }

    return 0;
}