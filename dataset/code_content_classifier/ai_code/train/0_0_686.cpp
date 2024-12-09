#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<Edge>> graph(V);
    vector<int> tape(V, INT_MAX);

    for (int i = 0; i < E; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        graph[s].push_back({t, c});
        graph[t].push_back({s, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    tape[0] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > tape[node]) {
            continue;
        }

        for (Edge& edge : graph[node]) {
            int new_dist = max(dist, edge.weight);
            if (new_dist < tape[edge.to]) {
                tape[edge.to] = new_dist;
                pq.push({new_dist, edge.to});
            }
        }
    }

    if (tape[V-1] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << tape[V-1] << endl;
    }

    return 0;
}