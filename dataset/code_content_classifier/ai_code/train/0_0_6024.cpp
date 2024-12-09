#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
vector<vector<pair<int, char>>> adj;
vector<int> subtreeSizes;
int smallestSize = 0;
int bestP = 0;

void dfs(int u, int p, int depth) {
    subtreeSizes[u] = 1;
    int maxChildSize = 0;
    for (auto& edge : adj[u]) {
        int v = edge.first;
        char c = edge.second;
        if (v == p) continue;
        dfs(v, u, depth + 1);
        subtreeSizes[u] += subtreeSizes[v];
        maxChildSize = max(maxChildSize, subtreeSizes[v]);
    }
    if (n - subtreeSizes[u] > maxChildSize) {
        if (depth > smallestSize) {
            smallestSize = depth;
            bestP = depth - 1;
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    subtreeSizes.resize(n + 1, 0);

    for (int i = 1; i < n; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(1, 0, 0);

    cout << smallestSize << endl;
    cout << bestP << endl;

    return 0;
}