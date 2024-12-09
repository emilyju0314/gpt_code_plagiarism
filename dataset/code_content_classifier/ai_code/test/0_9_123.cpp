#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int white[MAXN], red[MAXN], blue[MAXN];

void dfs(int u, int p) {
    white[u] = 1;
    red[u] = 0;
    blue[u] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        white[u] += white[v];
        red[u] += red[v];
        blue[u] += blue[v];
    }

    int remaining_red = min(white[u] - 1, red[u]);
    red[u] = min(remaining_red, red[u]);
    blue[u] = min(white[u] - 1, blue[u]);
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    long long result = 1LL * white[1] * (red[1] - blue[1]);
    cout << result << endl;

    return 0;
}