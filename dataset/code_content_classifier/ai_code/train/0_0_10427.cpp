#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int s1, s2, f;
    cin >> s1 >> s2 >> f;

    vector<vector<pair<int, int>>> adj(n+1);
    vector<pair<int, int>> fixedRoads;
    vector<tuple<int, int, int, int>> variableRoads;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    for (int i = 0; i < k; i++) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        variableRoads.push_back({a, b, l, r});
    }

    vector<int> dist(n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s1] = 0;
    pq.push({0, s1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int minDist = dist[f];
    
    vector<int> changeRoads(k, 1);

    for (int i = 0; i < k; i++) {
        int a, b, l, r;
        tie(a, b, l, r) = variableRoads[i];
        if (dist[s1] + dist[b] + l < minDist) {
            minDist = dist[s1] + dist[b] + l;
            changeRoads[i] = l;
        } else if (dist[s1] + dist[b] + r > minDist) {
            changeRoads[i] = minDist - dist[s1] - dist[b];
        }
    }

    if (minDist < INF) {
        cout << "WIN" << endl;
        for (int i = 0; i < k; i++) {
            cout << changeRoads[i] << " ";
        }
    } else {
        cout << "DRAW" << endl;
        for (int i = 0; i < k; i++) {
            cout << changeRoads[i] << " ";
        }
    }

    return 0;
}