#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    vector<vector<pii>> adj[N+1];
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b, d});
        adj[a].push_back({c, d});
        adj[b].push_back({a, d});
        adj[b].push_back({c, d});
        adj[c].push_back({a, d});
        adj[c].push_back({b, d});
    }

    int min_distance = INT_MAX;

    for (int i = 1; i <= N; i++) {
        vector<int> dist(N+1, INT_MAX);
        dist[s] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if (u == t) {
                min_distance = min(min_distance, w);
                break;
            }

            for (pii v : adj[u]) {
                if (w + v.second < dist[v.first]) {
                    dist[v.first] = w + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
    }

    cout << min_distance << endl;

    return 0;
}