#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 200005;
const long long INF = 1e18;

vector<pair<int, int>> fountains;
vector<pair<int, int>> adj[MAXN];
vector<long long> dist(MAXN, INF);

long long calc_distance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) * 100 + abs(p1.second - p2.second) * 100;
}

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1, y1, x2, y2, N;
    cin >> x1 >> y1 >> x2 >> y2 >> N;

    fountains.push_back({x1, y1});
    fountains.push_back({x2, y2});

    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        fountains.push_back({X, Y});
    }

    // Construct the adjacency list
    int n = fountains.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dist = calc_distance(fountains[i], fountains[j]);
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }

    dijkstra(0);

    cout << fixed << setprecision(15) << dist[1] << endl;

    return 0;
}