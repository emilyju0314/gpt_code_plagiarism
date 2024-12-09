#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n, m;
vector<int> monasteries;
vector<pair<int, int>> adj[MAXN];
int dist[MAXN], farthest_dist[MAXN], farthest_monastery[MAXN], cnt[MAXN], best, ways;

void dfs(int u, int p) {
    for (auto edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            dist[v] = dist[u] + w;
            if (find(monasteries.begin(), monasteries.end(), v) != monasteries.end()) {
                farthest_monastery[u] = v;
                farthest_dist[u] = dist[v];
            }
            dfs(v, u);
        }
    }
}

void update(int u, int p) {
    for (auto edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            update(v, u);
            if (farthest_dist[v] > farthest_dist[u]) {
                farthest_dist[u] = farthest_dist[v];
                farthest_monastery[u] = farthest_monastery[v];
            }
        }
    }
}

void count(int u, int p) {
    for (auto edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            cnt[u] += cnt[v];
            if (farthest_monastery[u] != farthest_monastery[v]) {
                best = max(best, cnt[v]);
                ways += (cnt[v] == best);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int monastery;
        cin >> monastery;
        monasteries.push_back(monastery);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dfs(1, 0);
    update(1, 0);

    for (int i = 1; i <= n; i++) {
        cnt[i] = (farthest_monastery[i] == monasteries[0] || farthest_monastery[i] == monasteries[1]);
    }

    best = 0;
    ways = 0;

    count(1, 0);

    cout << cnt[1] - best << " " << ways << endl;

    return 0;
}