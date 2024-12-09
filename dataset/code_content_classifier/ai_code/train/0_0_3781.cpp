#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist;
vector<int> criminals;
int ans = 0;

void dfs(int v, int p, int d) {
    dist[v] = d;
    for (auto u : adj[v]) {
        if (u.first != p) {
            dfs(u.first, v, d + u.second);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    dist.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int s;
    cin >> s;

    int m;
    cin >> m;

    criminals.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> criminals[i];
    }

    dfs(s, 0, 0);

    for (int i = 0; i < m; ++i) {
        ans = max(ans, dist[criminals[i]]);
    }

    if(ans == 0) {
        cout << "Terrorists win" << endl;
    } else {
        cout << 2 * ans << endl;
    }

    return 0;
}