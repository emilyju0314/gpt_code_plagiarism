#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100001;
vector<pair<int, int>> g[N];
int subtree[N], total[N], diameter[N], max_dist[N];

void dfs(int v, int par) {
    total[v] = 0;
    subtree[v] = 1;

    for (auto& edge : g[v]) {
        int u = edge.first, w = edge.second;
        if (u == par) continue;

        dfs(u, v);
        subtree[v] += subtree[u];
        total[v] += total[u] + w;
        max_dist[v] = max(max_dist[v], max_dist[u] + w);
    }
}

void solve() {
    int n, q, w;
    cin >> n >> q >> w;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    dfs(1, 0);
    int last = 0;

    for (int i = 0; i < q; i++) {
        int d, e;
        cin >> d >> e;
        d = (d + last) % (n - 1);
        e = (e + last) % w;

        int u = g[1][d].first, new_weight = e;
        int dist = total[1] - max_dist[u] + max(max_dist[u], new_weight);
        last = dist;
        cout << dist << endl;
    }
}

int main() {
    solve();
    return 0;
}