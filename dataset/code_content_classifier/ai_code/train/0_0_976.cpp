#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> colors;
vector<int> whiteCount, blackCount;
int totalRemovals;

void dfs(int u, int parent) {
    whiteCount[u] = (colors[u] == 1);
    blackCount[u] = (colors[u] == 2);

    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            whiteCount[u] += whiteCount[v];
            blackCount[u] += blackCount[v];
        }
    }

    int minRemovals = min(whiteCount[u], blackCount[u]);
    totalRemovals += (minRemovals * 2);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        adj.clear();
        colors.clear();
        whiteCount.clear();
        blackCount.clear();
        totalRemovals = 0;

        adj.resize(n);
        colors.resize(n);
        whiteCount.resize(n);
        blackCount.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> colors[i];
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        cout << totalRemovals << endl;
    }

    return 0;
}