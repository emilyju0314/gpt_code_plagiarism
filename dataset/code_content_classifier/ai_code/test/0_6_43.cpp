#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

int n, q;
vector<pair<int, int>> adj[MAXN];
int enjoyment[MAXN];
int parent[MAXN][MAXLOG];
int max_toll[MAXN][MAXLOG];
int depth[MAXN];

void dfs(int u, int p, int weight, int toll, int d) {
    parent[u][0] = p;
    max_toll[u][0] = toll;
    depth[u] = d;

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;

        if (v != p) {
            dfs(v, u, w, max(toll, weight), d + 1);
        }
    }
}

void preprocess() {
    dfs(1, 0, 0, 0, 0);

    for (int j = 1; j < MAXLOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != 0) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
                max_toll[i][j] = max(max_toll[i][j - 1], max_toll[parent[i][j - 1]][j - 1]);
            }
        }
    }
}

pair<int, int> query(int v, int x) {
    int highest_enjoyment = 0;
    int highest_toll = 0;

    for (int j = MAXLOG - 1; j >= 0; j--) {
        if (v >= (1 << j)) {
            highest_toll = max(highest_toll, max_toll[x][j]);
            x = parent[x][j];
            v -= (1 << j);
        }
    }

    highest_enjoyment = enjoyment[x];
    return {highest_enjoyment, highest_toll};
}

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> enjoyment[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    preprocess();

    while (q--) {
        int v, x;
        cin >> v >> x;
        pair<int, int> result = query(v, x);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}