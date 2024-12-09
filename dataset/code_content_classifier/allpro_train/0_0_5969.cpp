#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int N, M, S, T;
vector<vector<pii>> adj;
vector<int> minDist;
vector<int> secondMinDist;

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, S});
    minDist[S] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (minDist[v] > dist + weight) {
                secondMinDist[v] = minDist[v];
                minDist[v] = dist + weight;
                pq.push({minDist[v], v});
            } else if (secondMinDist[v] > dist + weight && minDist[v] != dist + weight) {
                secondMinDist[v] = dist + weight;
                pq.push({secondMinDist[v], v});
            }
        }
    }
}

int main() {
    cin >> N >> M >> S >> T;
    adj.resize(N + 1);
    minDist.assign(N + 1, INT_MAX);
    secondMinDist.assign(N + 1, INT_MAX);

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dijkstra();

    if (minDist[T] == INT_MAX || secondMinDist[T] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << max(minDist[T], secondMinDist[T]) << endl;
    }

    return 0;
}