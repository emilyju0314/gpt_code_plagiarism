#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

#define INF numeric_limits<long long>::max()

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<long long> max_snuuk(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        adj[u].push_back({v, a});
        adj[v].push_back({u, b});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [dist, city] = pq.top();
        pq.pop();
        if(max_snuuk[city] >= dist) {
            for(auto [next_city, fare] : adj[city]) {
                long long next_dist = dist + fare;
                if(max_snuuk[next_city] < next_dist) {
                    max_snuuk[next_city] = next_dist;
                    pq.push({next_dist, next_city});
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << 1000000000000000 - max_snuuk[t] + max_snuuk[t - i - 1] << endl;
    }

    return 0;
}