#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 50001;
const int MAXM = 50001;

int N, M, Q, MOD;
vector<pair<int, int>> adj[MAXN];
bool visited[MAXN];

bool dfs(int u, int t, int r, int curr_len) {
    if (u == t && curr_len % MOD == r) {
        return true;
    }
    visited[u] = true;
    for (const auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (!visited[v] && dfs(v, t, r, (curr_len + w) % MOD)) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M >> Q >> MOD;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 0; i < Q; i++) {
        int s, t, r;
        cin >> s >> t >> r;
        memset(visited, false, sizeof(visited));
        if (dfs(s, t, r, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}