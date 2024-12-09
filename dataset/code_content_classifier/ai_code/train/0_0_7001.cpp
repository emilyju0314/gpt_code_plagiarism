#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX / 2;

int dijkstra(map<string, vector<pair<string, int>>> &graph, string src, string dest, int cap) {
    map<string, int> dist;
    for (auto& p : graph) {
        dist[p.first] = INF;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (u == dest) {
            return d;
        }

        if (dist[u] < d) {
            continue;
        }

        for (auto& [v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return -1;
}

int main() {
    int N, M, cap;
    while (true) {
        cin >> N >> M >> cap;
        if (N == 0 && M == 0 && cap == 0) {
            break;
        }

        map<string, vector<pair<string, int>>> graph;
        string src, dest;
        cin >> src >> dest;

        for (int i = 0; i < N; i++) {
            string city1, city2;
            int dist;
            cin >> city1 >> city2 >> dist;
            graph[city1].push_back({city2, dist});
            graph[city2].push_back({city1, dist});
        }

        vector<string> lpgStations;
        for (int i = 0; i < M; i++) {
            string station;
            cin >> station;
            lpgStations.push_back(station);
        }

        int result = dijkstra(graph, src, dest, cap);
        cout << (result == -1 ? -1 : result * 2) << endl;
    }

    return 0;
}