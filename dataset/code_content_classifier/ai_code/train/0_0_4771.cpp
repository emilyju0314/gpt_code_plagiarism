#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 200005;

vector<int> adj[N];
vector<int> colors(N, 0);
int r = 0;

void dfs(int v, int p) {
    int color = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (color == colors[v] || color == colors[p]) color++;
        r = max(r, color);
        colors[u] = color;
        color++;
        dfs(u, v);
    }
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

    colors[1] = 1; // Arbitrary color to start the coloring process
    dfs(1, 0);

    cout << r << endl;
    for (int i = 1; i < n; i++) {
        cout << colors[i] << " ";
    }

    return 0;
}