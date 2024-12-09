#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

vector<pair<int, int>> adj[MAXN];
vector<int> color[MAXN];
vector<int> dist[MAXN];

void dfs(int v, int p) {
    for (auto u : adj[v]) {
        if (u.first != p) {
            dist[u.first][v] = dist[v][u.first] = u.second;
            dfs(u.first, v);
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
        color[c].push_back(d);
    }

    for (int i = 1; i <= N; i++) {
        dist[i].resize(N + 1, 0);
    }

    dfs(1, 0);

    for (int i = 0; i < Q; i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        long long ans = dist[u][v];
        for (int d : color[x]) {
            ans = min(ans, 1LL * dist[u][v] - d + y);
        }
        cout << ans << endl;
    }

    return 0;
}