#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

using namespace std;

struct Edge {
    int to;
    long long a, b;
};

const long long INF = numeric_limits<long long>::max();

int main() {
    int N, M, S, G;
    cin >> N >> M >> S >> G;

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V;
        long long A, B;
        cin >> U >> V >> A >> B;
        graph[U].push_back({V, A, B});
        graph[V].push_back({U, A, B});
    }

    vector<long long> dist(N + 1, INF);
    dist[S] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [curr_dist, curr_node] = pq.top();
        pq.pop();

        if (curr_node == G) {
            cout << curr_dist << endl;
            return 0;
        }

        if (dist[curr_node] < curr_dist) {
            continue;
        }

        for (const auto& edge : graph[curr_node]) {
            long long next_dist = curr_dist;
            if (next_dist % (edge.a + edge.b) < edge.a) {
                next_dist += edge.a - next_dist % (edge.a + edge.b);
            }
            next_dist += edge.a + edge.b;

            if (next_dist < dist[edge.to]) {
                dist[edge.to] = next_dist;
                pq.push({next_dist, edge.to});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}