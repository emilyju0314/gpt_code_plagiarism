#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1000000000

struct node {
    int idx;
    long long dist;

    bool operator<(const node& other) const {
        return dist > other.dist;
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> w(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    long long dist[n+1];
    fill(dist, dist+n+1, INF);
    dist[1] = 0;

    priority_queue<node> pq;
    pq.push({1, 0});

    while (!pq.empty()) {
        node curr = pq.top();
        pq.pop();

        for (auto next : adj[curr.idx]) {
            if (dist[next.first] > curr.dist + next.second) {
                dist[next.first] = curr.dist + next.second;
                pq.push({next.first, dist[next.first]});
            }
        }
    }

    vector<long long> ans;
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        sum += w[i] * (dist[i] - dist[1]);
    }
    ans.push_back(sum);

    int incidents = 0;
    while (incidents < q) {
        int k, x;
        cin >> k >> x;
        incidents++;

        sum -= (w[k] + x) * (dist[k] - dist[1]);
        w[k] += x;
        sum += w[k] * (dist[k] - dist[1]);

        ans.push_back(sum);
    }

    for (auto cost : ans) {
        cout << cost << endl;
    }

    return 0;
}