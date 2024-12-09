#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define MAXN 100005
#define MOD 1000000007
#define ll long long
using namespace std;

int N, M, S, T;
ll distS[MAXN], distT[MAXN];
vector<pair<int, int>> adjList[MAXN];

void dijkstra(int start, ll dist[]) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adjList[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

ll countShortestPaths() {
    ll ans = 0, shortestTime = distS[T];

    for (int u = 1; u <= N; u++) {
        for (auto [v, w] : adjList[u]) {
            if (distS[u] + w + distT[v] == shortestTime || distS[v] + w + distT[u] == shortestTime) {
                ans = (ans + 1) % MOD;
            }
        }
    }

    return ans;
}

int main() {
    cin >> N >> M >> S >> T;

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adjList[u].push_back({v, d});
        adjList[v].push_back({u, d});
    }

    dijkstra(S, distS);
    dijkstra(T, distT);

    ll ans = countShortestPaths();
    cout << ans << endl;

    return 0;
}