#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int white[MAXN], red[MAXN], blue[MAXN];

void dfs(int u, int parent) {
    white[u] = 1;
    red[u] = 0;
    blue[u] = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        
        white[u] += white[v];
        red[u] += red[v];
        blue[u] += blue[v];
    }

    if (red[u] < white[u]) red[u] = min(white[u], red[u] + 1);
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

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += white[i] * (red[i] - blue[i]);
    }

    cout << ans << endl;

    return 0;
}