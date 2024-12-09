#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> points;
vector<int> ans;

void dfs(int u, int p) {
    ans.push_back(u + 1);
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    points.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    sort(points.begin(), points.end());

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}