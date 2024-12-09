#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

int n, k;
vector<int> adj[MAXN];
int w[MAXN], r[MAXN], b[MAXN];
long long score = 0;

void dfs(int u, int p) {
    w[u] = 1;
    r[u] = 0;
    b[u] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        w[u] += w[v];
        r[u] += r[v];
        b[u] += b[v];
    }

    int remaining_red = k - r[u];
    int possible_red = min(remaining_red, w[u] - 1);
    r[u] += possible_red;
    b[u] = w[u] - 1 - r[u];

    score += (long long)w[u] * (r[u] - b[u]);
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << score << endl;

    return 0;
}