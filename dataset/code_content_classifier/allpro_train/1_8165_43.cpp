#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define fr first
#define sc second

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> adj(1 << N);
    for (int i = 0; i < N * (1 << (N - 1)); i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> lab(1 << N, -1), vis(1 << N);
    queue<int> bfs;
    bfs.push(0);
    vis[0] = 1;
    int pw = 0;
    for (int i : adj[0]) {
        lab[i] = 1 << pw++;
    }
    while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();
        if (lab[cur] == -1) {
            int v = 0;
            for (int nxt : adj[cur]) {
                if (lab[nxt] != -1) {
                    v |= lab[nxt];
                }
            }
            lab[cur] = v;
        }
        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                vis[nxt] = 1;
                bfs.push(nxt);
            }
        }
    }
    vector<int> per(1 << N);
    for (int i = 0; i < 1 << N; i++) {
        per[lab[i]] = i;
    }
    for (int i = 0; i < 1 << N; i++) {
        cout << per[i] << " \n"[i == (1 << N) - 1];
    }
    if (N & N - 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> col(1 << N);
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < N; j++) {
            col[per[i]] ^= j * (i >> j & 1);
        }
    }
    for (int i = 0; i < 1 << N; i++) {
        cout << col[i] << " \n"[i == (1 << N) - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
