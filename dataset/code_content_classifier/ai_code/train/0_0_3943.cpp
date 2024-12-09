#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

int n;
vector<vector<pair<int, int>>> adj;
vector<Edge> edges;

void dfs(int v, int p, int& ans) {
    for (auto& edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (u != p) {
            dfs(u, v, ans);
            ans += 2 * w;
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        edges.push_back({x, y, w});
    }

    int ans = 0;
    dfs(1, 0, ans);
    cout << ans << endl;

    return 0;
}