#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5+5;

int n, m, q;
int w[MAXN];
vector<pair<int, int>> adj[MAXN];
vector<tuple<int, int, int>> railways;
vector<pair<int, int>> incidents;
ll dist[MAXN];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void dijkstra(int start) {
    fill(dist, dist+n+1, LLONG_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        
        for (auto [v, len] : adj[u]) {
            ll new_dist = d + len;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
        railways.push_back({u, v, d});
    }

    for (int i = 0; i < q; i++) {
        int k, x;
        cin >> k >> x;
        incidents.push_back({k, x});
    }

    dijkstra(1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 2 * dist[i] * w[i];
    }
    cout << ans << "\n";

    for (auto [k, x] : incidents) {
        tie(k, x) = incidents[q];
        w[k] += x;
        dijkstra(1);

        ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += 2 * dist[i] * w[i];
        }
        cout << ans << "\n";
    }

    return 0;
}